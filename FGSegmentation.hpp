#ifndef FGSEGMENTATION_HPP
#define FGSEGMENTATION_HPP

#include <queue>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/objdetect/objdetect.hpp>

class WatershedSegmenter{ // used in foreground segmentation
private:
    cv::Mat markers;
public:
    void setMarkers(const cv::Mat &markerImage){
        markerImage.convertTo(markers,CV_32S);
    }
    cv::Mat process(const cv::Mat &image){
        cv::watershed(image,markers);
        return markers;
    }
};

class FGSegmentation{

    cv::BackgroundSubtractorMOG mog;
    WatershedSegmenter segmenter;
    cv::Mat fg,tmp,markers;

    std::queue<cv::Point> _queue;
    cv::Mat mark;
    cv::Point p,np;
    cv::Rect superPixel;

    void segment(const cv::Mat &frame){

        cv::cvtColor(frame,tmp,CV_BGR2GRAY);
        cv::equalizeHist(tmp,tmp);
        mog(tmp,tmp,0.005);  // mixture of gaussian algorithm
        cv::medianBlur(tmp,tmp,5);
        cv::medianBlur(tmp,tmp,5);

        cv::dilate(tmp,fg,cv::Mat(),cv::Point(-1,-1),20);
        markers=fg+128;
        segmenter.setMarkers(markers);
        segmenter.process(frame).convertTo(fg,CV_8U);

    }

    bool findNeighbor(int dir,const cv::Point& now,cv::Point &next,int w,int h){
        // find the neighbor in the specified direction
        next=now;
        switch(dir){
            case 0:
                next.y--;
                break;
            case 1:
                next.y++;
                break;
            case 2:
                next.x--;
                break;
            case 3:
                next.x++;
                break;
            default:
                assert(false);
        }
        // bounding
        if(next.x<0) return false;
        if(next.x==w) return false;
        if(next.y<0) return false;
        if(next.y==h) return false;
        return true;
    }

    bool contain(const cv::Rect &a, const cv::Rect &b){
        if(a.x<=b.x)
            if(a.y<=b.y)
                if(a.x+a.width>=b.x+b.width)
                    if(a.y+a.height>=b.y+b.height)
                        return true;
        return false;
    }

    void boundingBoxes(std::vector<cv::Rect> *result){
        result->clear();
        int typeNum=0;
        mark.create(fg.size(),CV_32S);
        int w=fg.size().width,h=fg.size().height,x,y,z;
        for(y=0;y<h;y++){
            for(x=0;x<w;x++){
                mark.at<int>(y,x)=0;  // set zeros
            }
        }
        uchar *pdata,tttmp;
        for(y=0;y<h;y++){
            pdata=fg.ptr<uchar>(y);
            for(x=0;x<w;x++){
                if(pdata[x]==255){
                    if(mark.at<int>(y,x)==0){
                        typeNum++;
                        int tlx=x,tly=y,brx=x,bry=y;
                        mark.at<int>(y,x)=typeNum;
                        p.x=x;
                        p.y=y;
                        _queue.push(p);
                        while(!(_queue.empty())){  // find all pixels connect to (x,y)
                            p=_queue.front();
                            _queue.pop();
                            for(z=0;z<4;z++){
                                if(findNeighbor(z,p,np,w,h)){
                                    tttmp=fg.at<uchar>(np.y,np.x);
                                    if(tttmp==255){
                                        if(mark.at<int>(np.y,np.x)==0){
                                            tlx=std::min(tlx,np.x);
                                            brx=std::max(brx,np.x);
                                            tly=std::min(tly,np.y);
                                            bry=std::max(bry,np.y);
                                            mark.at<int>(np.y,np.x)=typeNum;
                                            _queue.push(np);
                                        }
                                    }
                                }
                            }
                        }
                        superPixel.x=tlx;
                        superPixel.y=tly;
                        superPixel.height=bry-tly;
                        superPixel.width=brx-tlx;
                        bool flag=true;
                        for(auto &bbox: *result){
                            if(contain(superPixel,bbox)){
                                bbox=superPixel;
                                flag=false;
                                break;
                            }
                            if(contain(bbox,superPixel)){
                                flag=false;
                                break;
                            }
                        }
                        if(flag)
                            result->push_back(superPixel);
                    }
                }
            }
        }
    }

public:

    void processFrame(const cv::Mat &frame,std::vector<cv::Rect> &result){
        segment(frame);
        boundingBoxes(&result);
    }
};

#endif // FGSEGMENTATION_HPP

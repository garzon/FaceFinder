#ifndef FRAMEPROCESSOR_HPP
#define FRAMEPROCESSOR_HPP

#include <vector>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;

class FaceDetection{

    cv::HOGDescriptor hog;
    cv::Mat ROI;
    std::vector<cv::Rect> tmp;

public:

    FaceDetection():
        hog(cv::Size(48,48), cv::Size(16,16), cv::Size(8,8), cv::Size(8,8), 9)
        // set properties
    {
        hog.load("hog_head.xml");  // load the classifier
    }

    void processFrame(const cv::Mat &frame,const std::vector<cv::Rect> &ROIs,std::vector<cv::Rect> &results){
        results.clear();
        for(const auto &bbox: ROIs){
            ROI=frame(bbox);
            tmp.clear();
            if(ROI.rows>=48)
                if(ROI.cols>=48)
                    hog.detectMultiScale(ROI, tmp, 1, cv::Size(8,8), cv::Size(0,0), 1.1, 3, false);
            for(cv::Rect &face: tmp){
                face.x+=bbox.x;
                face.y+=bbox.y;
                if(face.height*1.3+face.y<frame.rows)
                    face.height=floor(face.height*1.3);              // expand
                results.push_back(face);
            }
        }
    }
};



#endif // FRAMEPROCESSOR_HPP

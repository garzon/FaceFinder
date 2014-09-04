#ifndef FRAMEPROCESSOR_HPP
#define FRAMEPROCESSOR_HPP

#include "FduVideo_lib.hpp"
#include "system_struct.hpp"

using namespace cv;

class BodyDetection{

    CascadeClassifier cascade;
    cv::Mat img;
    std::vector<cv::Rect> tmp;

    const options &_ops;

public:

    BodyDetection(const options &ops):
        _ops(ops)
        // set properties
    {
        if(!cascade.load(ops.face_d._body))
            std::cout<<"BD Error"<<std::endl;
    }

    void processFrame(shared_data &data){
        shared_data::bbox bodytmp;
        vector<shared_data::bbox> tmpROI;
        for(const auto &bbox: data.im_data.im_ROI){
            img=data.im_data.image(bbox);
            tmp.clear();

            Mat gray;

            cvtColor( img, gray, CV_BGR2GRAY );
            equalizeHist( gray, gray );

            cascade.detectMultiScale(gray,tmp,1.1,2,CV_HAAR_SCALE_IMAGE);

            for(cv::Rect &body: tmp){
                body.x+=bbox.x;

                // expand
                body.y+=bbox.y-body.height;
                body.height=round(body.height*1.5);
                if(body.y<0){
                    if(body.height>=data.im_data.image.rows)
                        body.height+=body.y;
                    body.y=0;
                }

                bodytmp=shared_data::bbox(body);
                bodytmp.type_label=TYPE_PERSON;                              // means that it's body
                data.im_boxes.push_back(bodytmp);

            }
        }

    }
};

class FaceDetection{

    cv::HOGDescriptor hog;
    cv::Mat ROI;
    std::vector<cv::Rect> tmp;
    BodyDetection BD;
    const options &_ops;

public:

    FaceDetection(const options &ops):
        _ops(ops),BD(ops),
        hog(cv::Size(48,48), cv::Size(16,16), cv::Size(8,8), cv::Size(8,8), 9)
        // set properties
    {
        hog.load(_ops.face_d._hog_head);  // load the classifier
    }

    void processFrame(shared_data &data){
        shared_data::bbox facetmp;
        for(const auto &bbox: data.im_data.im_ROI){
            ROI=data.im_data.image(bbox);
            tmp.clear();
            if(ROI.rows>=48)
                if(ROI.cols>=48)
                    hog.detectMultiScale(ROI, tmp, 1, cv::Size(8,8), cv::Size(0,0), 1.1, 3, false);
            for(cv::Rect &face: tmp){
                face.x+=bbox.x;
                face.y+=bbox.y;
                if(face.height*1.3+face.y<data.im_data.image.rows)
                    face.height=floor(face.height*1.3);              // expand
                facetmp=shared_data::bbox(face);
                facetmp.type_label=TYPE_FACE;                              // means that it's a face
                data.im_boxes.push_back(facetmp);
            }
        }
        // BD ----------------------------------------------
        //BD.processFrame(data);
    }
};



#endif // FRAMEPROCESSOR_HPP

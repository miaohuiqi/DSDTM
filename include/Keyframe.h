//
// Created by buyi on 17-11-9.
//

#ifndef DSDTM_KEYFRAME_H
#define DSDTM_KEYFRAME_H

#include "Camera.h"
#include "Frame.h"
#include "MapPoint.h"

namespace DSDTM
{

class MapPoint;

class KeyFrame
{
public:
    KeyFrame(Frame &_frame);
    ~KeyFrame();

    //! Add MapPoint and the observation between mappoint and features
    void Add_MapPoint(MapPoint *tMPoint);
    void Add_Observations(long int tId, MapPoint *tMPoint);

    //! Return Observations
    std::map<size_t, MapPoint*> Get_Observations() const { return mpObservation;};

    //! Get and Set Keyframe pose
    Sophus::SE3 Get_Pose() { return mT_c2w; }
    void Set_Pose(Sophus::SE3 tPose) { mT_c2w = tPose; }


public:
    unsigned long           mlId;
    static unsigned long    mlNextId;

    Features                mvFeatures;
    std::vector<MapPoint*>  mvMapPoints;
    std::map<size_t, MapPoint*>  mpObservation;

protected:
    Frame                   *mFrame;

    Sophus::SE3             mT_c2w;

};

} //DSDTM



#endif //DSDTM_KEYFRAME_H

//
// Created by buyi on 17-11-4.
//

#ifndef DSDTM_MAPPOINT_H
#define DSDTM_MAPPOINT_H

#include "Camera.h"
#include "Frame.h"
#include "Feature.h"
#include "Keyframe.h"


namespace DSDTM
{

class KeyFrame;
class Frame;

class MapPoint
{
public:
    MapPoint();
    MapPoint(Eigen::Vector3d& _pose, KeyFrame *_frame);

    //! Set and Get the world position of mappoint
    void Set_Pose(Eigen::Vector3d tPose);
    Eigen::Vector3d Get_Pose();

    //! Add Mappoint observation
    void Add_Observation(KeyFrame *tKFrame, size_t tfID);

    //! Set mappoint bad
    void SetBadFlag();


protected:

public:
    unsigned long           mlID;
    static unsigned long    mlNextId;

    bool                    mbOutlier;

protected:

    Eigen::Vector3d         mPose;

    //! the frame first observe this point
    unsigned long           mFirstFrame;

    //! Observation
    size_t                  mObserveNum;
    std::map<KeyFrame*, size_t>         mObservations;

};


} // namesapce DSDTM




#endif //DSDTM_MAPPOINT_H

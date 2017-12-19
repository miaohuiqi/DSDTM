//
// Created by buyi on 17-11-9.
//
#include "Keyframe.h"


namespace DSDTM
{
long unsigned int KeyFrame::mlNextId=0;
KeyFrame::KeyFrame(Frame &tframe):
        mFrame(&tframe), mT_c2w(tframe.Get_Pose()), mvMapPoints(tframe.mvMapPoints),
        mvFeatures(tframe.mvFeatures)
{
    mlId = mlNextId++;

    std::for_each(tframe.mpObservation.begin(), tframe.mpObservation.end(), [&](std::pair<size_t , MapPoint*> tObs)
    {
        Add_Observations(tObs.first, tObs.second);
    });

}

KeyFrame::~KeyFrame()
{

}

void KeyFrame::Add_MapPoint(MapPoint *tMPoint)
{
    mvMapPoints.push_back(tMPoint);

}

void KeyFrame::Add_Observations(size_t tId, MapPoint *tMPoint)
{
    mpFFObservation.insert(std::pair<long int, size_t>(mvFeatures[tId].mlId, tId));
    mpObservation.insert(std::pair<long int, MapPoint*>(mvFeatures[tId].mlId, tMPoint));
}

std::vector<MapPoint*> KeyFrame::GetMapPoints()
{
    return mvMapPoints;
}

void KeyFrame::Set_Pose(Sophus::SE3 tPose)
{
    mT_c2w = tPose;

    Sophus::SE3 tT_w2c = mT_c2w.inverse();
    mR_w2c = tT_w2c.so3();
    mOw = tT_w2c.translation();
}

} //namesapce DSDTM
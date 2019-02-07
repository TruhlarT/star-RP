#include "StRpsPreTrackPoint.h"
#include "StRpsPreTrack.h"

#include "StRpsTrackPoint.h"
#include "StRpsTrack.h"

#include <cmath>

ClassImp(StRpsPreTrack)

StRpsPreTrack::StRpsPreTrack(){
    for(unsigned int i=0; i<mNumberOfStationsInBranch; ++i)
        mTrackPoints[ i ] = nullptr;
    mBranch = -1;
    mType = rpsUndefined;
}

StRpsPreTrack::StRpsPreTrack(const StRpsPreTrack& track) {
    *this = track;
}

StRpsPreTrack::~StRpsPreTrack() { /* no op */ }

StRpsPreTrack& StRpsPreTrack::operator=(const StRpsPreTrack& track) {
    if (this != &track) {
        for(unsigned int i=0; i<mNumberOfStationsInBranch; ++i){
            mTrackPoints[i] = const_cast<StRpsPreTrackPoint*>(track.trackPoint(i));
        }
        mP = track.pVec();
        mType = track.type();
    }
    return *this;
}

unsigned int StRpsPreTrack::planesUsed() const {
    unsigned int nPlanes = 0;
    for(unsigned int i=0; i<mNumberOfStationsInBranch; ++i)
        nPlanes += mTrackPoints[i].GetObject() ? trackPoint(i)->planesUsed() : 0;
    return nPlanes;
}

double StRpsPreTrack::thetaRp(unsigned int coordinate) const {
    if(coordinate>rpsAngleTheta) return 0.0;
    if(mType==rpsLocal) return theta(coordinate);
    TVector3 deltaVector = trackPoint(1)->positionVec() - trackPoint(0)->positionVec();
    return atan((coordinate<rpsAngleTheta ? deltaVector[coordinate] : deltaVector.Perp())/abs(deltaVector.z()));
}

double StRpsPreTrack::phiRp() const{
    if(mType==rpsLocal) return phi();
    TVector3 deltaVector = trackPoint(1)->positionVec() - trackPoint(0)->positionVec();
    return deltaVector.Phi();
}

double StRpsPreTrack::time() const{
    double sumTime=0.0;
    unsigned int numberOfPmtsWithSignal=0;
    for(unsigned int i=0; i<mNumberOfStationsInBranch; ++i){
        if(trackPoint(i))
            for(int j=0; j<trackPoint(i)->mNumberOfPmtsInRp; ++j){
                if(trackPoint(i)->time(j)>0){
                    sumTime += trackPoint(i)->time(j);
                    ++numberOfPmtsWithSignal;
                }
            }
    }
    return numberOfPmtsWithSignal>0 ? sumTime/numberOfPmtsWithSignal : -1;
}

double StRpsPreTrack::theta(unsigned int coordinate) const{
    return coordinate < mNumberOfAngleTypes ? atan((coordinate<rpsAngleTheta ? mP[coordinate] : mP.Perp())/abs(mP.z())) : 0.0;
}

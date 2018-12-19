#include "StRpsPreTrackPoint.h"
#include "StRpsTrackPoint.h"

ClassImp(StRpsPreTrackPoint)

StRpsPreTrackPoint::StRpsPreTrackPoint() {
    mRpId = -1;
    for (unsigned int i=0; i<StRpsTrackPoint::mNumberOfPlanesInRp; ++i) mClusterId[i] = -1;
    for (unsigned int i=0; i<StRpsTrackPoint::mNumberOfPmtsInRp; ++i) mTime[i] = -1;
    mQuality = rpsNotSet; // mQuality = StRpsPreTrackPoint::StRpsPreTrackPointQuality::rpsNotSet
}

StRpsPreTrackPoint::StRpsPreTrackPoint(const StRpsPreTrackPoint& trackPoint) {
    *this = trackPoint;
}

StRpsPreTrackPoint::~StRpsPreTrackPoint() { /* no op */ }

StRpsPreTrackPoint& StRpsPreTrackPoint::operator=(const StRpsPreTrackPoint& trackPoint) {
    if (this != &trackPoint) {
        mPosition = trackPoint.positionVec();
        mRpId = trackPoint.rpId();
        for (unsigned int i=0; i<StRpsTrackPoint::mNumberOfPlanesInRp; ++i ) mClusterId[i] = trackPoint.clusterId(i);
        for (unsigned int i=0; i<StRpsTrackPoint::mNumberOfPmtsInRp; ++i ) mTime[i] = trackPoint.time(i);
        mQuality = (StRpsPreTrackPoint::StRpsPreTrackPointQuality)trackPoint.quality();
    }
    return *this;
}

unsigned int StRpsPreTrackPoint::planesUsed() const {
    unsigned int nPlanesUsed = 0;
    for(unsigned int i=0; i<StRpsTrackPoint::mNumberOfPlanesInRp; ++i)
        if (mClusterId[i]>-1) ++nPlanesUsed;
    return nPlanesUsed;
}
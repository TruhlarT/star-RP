#ifndef __StRpsPreTrackPoint_hh__
#define __StRpsPreTrackPoint_hh__

#include "TObject.h"
#include "TVector3.h"

// #include "StEvent/StRpsTrackPoint.h"

class StRpsTrackPoint;

class StRpsPreTrackPoint : public TObject {

public:
    enum StRpsPreTrackPointQuality {rpsNormal, rpsGolden, rpsNotSet};
    enum {mNumberOfPmtsInRp = 2, mNumberOfPlanesInRp = 4};
protected:

	// position (x, y, z)
	TVector3	mPosition;
	// 	RP# (e.g. E1U=0)
	Int_t		mRpId;
	// IDs of clusters in RpsCollection
	Int_t 		mClusterId[mNumberOfPlanesInRp];
	// Track Point Quality
    StRpsPreTrackPointQuality mQuality;
    // time
    double mTime[mNumberOfPmtsInRp];

public:
	StRpsPreTrackPoint();
    StRpsPreTrackPoint(const StRpsPreTrackPoint&);
	~StRpsPreTrackPoint();

    StRpsPreTrackPoint& operator=(const StRpsPreTrackPoint&);

	TVector3 positionVec() const;
    Int_t rpId() const;
    Int_t clusterId(unsigned int planeId ) const;
    double time(unsigned int) const;
    StRpsPreTrackPointQuality quality() const;
    
    double x() const;
    double y() const;
    double z() const;
    
    void setPosition(const TVector3&);
    void setRpId(Int_t);
    void setClusterId(Int_t, unsigned int);
    void setQuality(StRpsPreTrackPointQuality quality);
    unsigned int planesUsed() const;

    void setTime(double, unsigned int);


private:

	ClassDef(StRpsPreTrackPoint,1)
};

inline TVector3 StRpsPreTrackPoint::positionVec() const { return mPosition; }
inline Int_t StRpsPreTrackPoint::rpId() const { return mRpId; }
inline Int_t StRpsPreTrackPoint::clusterId(unsigned int planeId ) const {
    return planeId<mNumberOfPlanesInRp ? mClusterId[planeId] : -1;
}
inline StRpsPreTrackPoint::StRpsPreTrackPointQuality StRpsPreTrackPoint::quality() const { return mQuality; }
inline double StRpsPreTrackPoint::x() const { return mPosition.x(); }
inline double StRpsPreTrackPoint::y() const { return mPosition.y(); }
inline double StRpsPreTrackPoint::z() const { return mPosition.z(); }

inline void StRpsPreTrackPoint::setPosition(const TVector3& position){
    mPosition = position;
}
inline void StRpsPreTrackPoint::setRpId(Int_t rpId) { mRpId = rpId; }
inline void StRpsPreTrackPoint::setClusterId(int clusterId, unsigned int planeId) {
    if( planeId<mNumberOfPlanesInRp )
        mClusterId[planeId] = clusterId;
}
inline void StRpsPreTrackPoint::setQuality(StRpsPreTrackPointQuality quality ) {
    mQuality = quality;
}
inline double StRpsPreTrackPoint::time(unsigned int pmtId) const {
    return pmtId<mNumberOfPmtsInRp ? mTime[pmtId] : -1;
}
inline void StRpsPreTrackPoint::setTime(double timeVal, unsigned int pmtId){
    if( pmtId<mNumberOfPmtsInRp ) mTime[pmtId] = timeVal;
}



#endif
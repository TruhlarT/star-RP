/***************************************************************************
 *
 * $Id: StRpsTrackPoint.h,v 2.2 2015/10/07 17:30:13 ullrich Exp $
 *
 * Author: Rafal Sikora, 1 Oct 2015
 *
 ***************************************************************************
 *
 * Description: StRpsTrackPoint class representing reconstructed (x,y,z)
 * position of the hit in single Roman Pot detector
 *
 ***************************************************************************
 *
 * $Log: StRpsTrackPoint.h,v $
 * Revision 2.2  2015/10/07 17:30:13  ullrich
 * Changed const to enums and related changes.
 *
 * Revision 2.1  2015/10/02 19:48:14  ullrich
 * Initial Revision.
 *
 **************************************************************************/
#ifndef StRpsTrackPoint_h
#define StRpsTrackPoint_h

#include "TObject.h"  // "StObject.h"
#include "TVector3.h" // "StThreeVectorF.h"


class StRpsTrackPoint : public TObject {
public:
    StRpsTrackPoint();
    StRpsTrackPoint(const StRpsTrackPoint&);
    ~StRpsTrackPoint();
    
    StRpsTrackPoint& operator=(const StRpsTrackPoint&);
    enum StRpsTrackPointQuality {rpsNormal, rpsGolden, rpsNotSet};
    
    TVector3 positionVec() const;
    int rpId() const;
    int clusterId(unsigned int) const;
    double time(unsigned int) const;
    StRpsTrackPointQuality quality() const;
    unsigned int planesUsed() const;
    
    double x() const;
    double y() const;
    double z() const;
    
    void setPosition(const TVector3&);
    void setRpId(int);
    void setClusterId(int, unsigned int);
    void setTime(double, unsigned int);
    void setQuality(StRpsTrackPointQuality);

    enum {mNumberOfPmtsInRp = 2, mNumberOfPlanesInRp = 4};
    
private:
    int mRpId;
    int mClusterId[mNumberOfPlanesInRp];
    double mTime[mNumberOfPmtsInRp];

    TVector3         mPosition;
    StRpsTrackPointQuality mQuality;

    ClassDef( StRpsTrackPoint, 1 )
};

inline TVector3 StRpsTrackPoint::positionVec() const { return mPosition; }
inline int StRpsTrackPoint::rpId() const { return mRpId; }
inline int StRpsTrackPoint::clusterId(unsigned int planeId ) const
{
    return planeId<mNumberOfPlanesInRp ? mClusterId[planeId] : -1;
}
inline double StRpsTrackPoint::time(unsigned int pmtId) const
{
    return pmtId<mNumberOfPmtsInRp ? mTime[pmtId] : -1;
}
inline StRpsTrackPoint::StRpsTrackPointQuality StRpsTrackPoint::quality() const { return mQuality; }
inline double StRpsTrackPoint::x() const { return mPosition.x(); }
inline double StRpsTrackPoint::y() const { return mPosition.y(); }
inline double StRpsTrackPoint::z() const { return mPosition.z(); }

inline void StRpsTrackPoint::setPosition(const TVector3& position)
{
    mPosition = position;
}
inline void StRpsTrackPoint::setRpId(int rpId) { mRpId = rpId; }
inline void StRpsTrackPoint::setClusterId(int clusterId, unsigned int planeId)
{
    if( planeId<mNumberOfPlanesInRp )
        mClusterId[planeId] = clusterId;
}
inline void StRpsTrackPoint::setTime(double timeVal, unsigned int pmtId)
{
    if( pmtId<mNumberOfPmtsInRp ) mTime[pmtId] = timeVal;
}
inline void StRpsTrackPoint::setQuality(StRpsTrackPoint::StRpsTrackPointQuality quality )
{
    mQuality = quality;
}

#endif

#ifndef __StRpsPreTrack_hh__
#define __StRpsPreTrack_hh__

#include "TObject.h"
#include "TVector3.h"
#include "TRef.h"
#include <vector>

using namespace std;

class StRpsTrackPoint;
class StRpsTrack;

class StRpsPreTrack : public TObject {
public:
	enum StRpsPreTrackType { rpsLocal, rpsGlobal, rpsUndefined };
    enum StRpsPreAngles { rpsAngleThetaX, rpsAngleThetaY, rpsAngleTheta, mNumberOfAngleTypes };
    enum {mNumberOfStationsInBranch = 2};

protected:
    TRef mTrackPoints[mNumberOfStationsInBranch];   // reference to track points (local tracks)
    TVector3 mP;								    // three-vector with reconstructed track momentum
    Int_t          mBranch;                         // detectors branch, EU=0, ED=1, WU=2, WD=3 
    StRpsPreTrackType mType;                         // type of the track
    
public:
    StRpsPreTrack();
    StRpsPreTrack(const StRpsPreTrack&);
    ~StRpsPreTrack();

    StRpsPreTrack& operator=(const StRpsPreTrack&);

    const StRpsPreTrackPoint* trackPoint(unsigned int)const ;
    TVector3 pVec() const;
    int branch() const;
    StRpsPreTrackType type() const;
    unsigned int planesUsed() const;
    
    double theta(unsigned int = rpsAngleTheta) const;
    double thetaRp(unsigned int = rpsAngleTheta) const;
    double phi() const;
    double phiRp() const;
    double t(double) const;
    double xi(double) const;
    double p() const;
    double pt() const;
    double eta() const;
    double time() const;

    void setTrackPoint( StRpsPreTrackPoint*, unsigned int);
    void setP(const TVector3&);
    void setBranch(int);
    void setType(StRpsPreTrackType type);
    
    ClassDef(StRpsPreTrack, 1)
};

inline const StRpsPreTrackPoint* StRpsPreTrack::trackPoint(unsigned int station) const {
    return station < mNumberOfStationsInBranch ? static_cast<const StRpsPreTrackPoint*>(mTrackPoints[station].GetObject()) : nullptr;
}
inline TVector3 StRpsPreTrack::pVec() const { return mP; }
inline int StRpsPreTrack::branch() const { return mBranch; }
inline StRpsPreTrack::StRpsPreTrackType StRpsPreTrack::type() const { return mType; }
inline double StRpsPreTrack::phi() const { return mP.Phi(); }
inline double StRpsPreTrack::t(double beamMomentum) const {
  return -2*beamMomentum*beamMomentum*(1-xi(beamMomentum))*(1-cos(theta(rpsAngleTheta)));
}
inline double StRpsPreTrack::xi(double beamMomentum) const {
    return (beamMomentum - mP.Mag())/beamMomentum;
}
inline double StRpsPreTrack::p() const { return mP.Mag(); }
inline double StRpsPreTrack::pt() const { return mP.Perp(); }
inline double StRpsPreTrack::eta() const { return mP.PseudoRapidity(); }

inline void StRpsPreTrack::setTrackPoint(StRpsPreTrackPoint* trackPoint, unsigned int station) {
    if (station<mNumberOfStationsInBranch)
        mTrackPoints[station] = trackPoint;
}
inline void StRpsPreTrack::setP(const TVector3& P) { mP = P; }
inline void StRpsPreTrack::setBranch(int branch) { mBranch = branch; }
inline void StRpsPreTrack::setType(StRpsPreTrackType type) { mType = type; }

#endif

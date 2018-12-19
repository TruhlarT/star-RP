#ifndef __StRpsPreCollection_hh__
#define __StRpsPreCollection_hh__

#include "TObject.h"
#include <vector>
#include <map>


#include "StRpsPreTrackPoint.h"
#include "StRpsPreTrack.h"
#include "TClonesArray.h"

using namespace std;



class StRpsCollection;

class StRpsPreCollection : public TObject {

public:

	StRpsPreCollection() {; }
	StRpsPreCollection(const StRpsCollection& vertex);
	~StRpsPreCollection() {;}

//Event level info

	unsigned char siliconBunch() const;

//Roman pot Level Info

     unsigned int numberOfRomanPots() const  { return mNumberOfRomanPot; }
     unsigned int numberOfPlanesWithClusters(int romanPotId) const;
     unsigned int adc(int romanPotId, unsigned int) const;
     unsigned int tac(int romanPotId, unsigned int) const;
     unsigned char status(int romanPotId) const;

//Plane level Info

	unsigned int numberOfPlanes() const { return mNumberOfPlanes; }
	double offsetPlane(int romanPotId, int planeId) const;
	double zPlane(int romanPotId, int planeId) const;
	double anglePlane(int romanPotId, int planeId) const;
	short  orientationPlane(int romanPotId, int planeId) const;
	unsigned char statusPlane(int romanPotId, int planeId) const;

//Cluster level Info

	int numberOfClusters(int romanPotId, int planeId) const;
	double positionCluster(int romanPotId, int planeId, int cluster) const;
	double positionRMSCluster(int romanPotId, int planeId, int cluster) const;
	short lengthCluster(int romanPotId, int planeId, int cluster) const;
	double energyCluster(int romanPotId, int planeId, int cluster) const;
	double xyCluster(int romanPotId, int planeId, int cluster) const;
	unsigned char qualityCluster(int romanPotId, int planeId, int cluster) const;

// Tracks and Track Points
	StRpsPreTrackPoint* trackPoint( unsigned int i ) { if ( i < mTrackPoints.size() ) return mTrackPoints[i]; return nullptr; }
	StRpsPreTrack* track( unsigned int i ) { if ( i < mTracks.size() ) return mTracks[i]; return nullptr; }

	inline int numberOfTrackPoints() const { return mTrackPoints.size(); }
	inline int numberOfTracks() const { return mTracks.size(); }
	
private:

     enum {mNumberOfRomanPot = 8, mNumberOfPlanes = 4};

	unsigned char mSiliconBunch;

	int mNumberPlanes[mNumberOfRomanPot];
	int mNumberPlanesWithClusters[mNumberOfRomanPot];
	unsigned char mStatusRomanPot[mNumberOfRomanPot];
	int mADC[mNumberOfRomanPot][2];
	int mTAC[mNumberOfRomanPot][2];	

	double mOffsetPlane[mNumberOfRomanPot][mNumberOfPlanes];
	double mzPlane[mNumberOfRomanPot][mNumberOfPlanes];
	double mAnglePlane[mNumberOfRomanPot][mNumberOfPlanes];
	short mOrientationPlane[mNumberOfRomanPot][mNumberOfPlanes];		
	unsigned char mStatusPlane[mNumberOfRomanPot][mNumberOfPlanes];	
	int mNumberOfClusters[mNumberOfRomanPot][mNumberOfPlanes];

	vector<double> mPositionCluster[mNumberOfRomanPot][mNumberOfPlanes];
	vector<double> mPositionRMSCluster[mNumberOfRomanPot][mNumberOfPlanes];
	vector<short> mLengthCluster[mNumberOfRomanPot][mNumberOfPlanes];
	vector<double> mEnergyCluster[mNumberOfRomanPot][mNumberOfPlanes];
	vector<double> mXYCluster[mNumberOfRomanPot][mNumberOfPlanes];		
	vector<unsigned char> mQualityCluster[mNumberOfRomanPot][mNumberOfPlanes];

	vector<StRpsPreTrackPoint*> 	mTrackPoints;
	vector<StRpsPreTrack*> 		mTracks;

	StRpsPreTrackPoint* addTrackPoint( StRpsTrackPoint* tp );

	// keeps an in-memory map of the StEvent TrackPoints to the 
	// StMuDst TrackPoints - for recovering the relationship in StRpsPreTracks
	map<StRpsTrackPoint *, StRpsPreTrackPoint * > mTrackPointsMap;		//! 


ClassDef(StRpsPreCollection,3)

};
inline unsigned char StRpsPreCollection::siliconBunch() const { return mSiliconBunch ; }
inline unsigned int StRpsPreCollection::numberOfPlanesWithClusters(int romanPotId) const { return romanPotId < mNumberOfRomanPot ? mNumberPlanesWithClusters[romanPotId] : 0; }
inline unsigned char StRpsPreCollection::status(int romanPotId) const { 
	if  (romanPotId < mNumberOfRomanPot) return mStatusRomanPot[romanPotId];
	else return 0;
}

inline unsigned int StRpsPreCollection::adc(int romanPotId, unsigned int n) const { return romanPotId < mNumberOfRomanPot && n < 2 ? mADC[romanPotId][n] : 0;}
inline unsigned int StRpsPreCollection::tac(int romanPotId, unsigned int n) const { return romanPotId < mNumberOfRomanPot && n < 2 ? mTAC[romanPotId][n] : 0;}
inline double StRpsPreCollection::offsetPlane(int romanPotId, int planeId) const {  return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes ? mOffsetPlane[romanPotId][planeId] : 0;}
inline double StRpsPreCollection::zPlane(int romanPotId, int planeId) const {  return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes ? mzPlane[romanPotId][planeId] : 0;}
inline double StRpsPreCollection::anglePlane(int romanPotId, int planeId) const {  return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes ? mAnglePlane[romanPotId][planeId] : 0;}
inline short  StRpsPreCollection::orientationPlane(int romanPotId, int planeId) const {  return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes ? mOrientationPlane[romanPotId][planeId] : 0;}
inline unsigned char StRpsPreCollection::statusPlane(int romanPotId, int planeId) const {
	if(romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes) return mStatusPlane[romanPotId][planeId];
	else return 0;
}
inline int StRpsPreCollection::numberOfClusters(int romanPotId, int planeId) const { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes ? mNumberOfClusters[romanPotId][planeId] : 0;}
inline double  StRpsPreCollection::positionCluster(int romanPotId, int planeId, int cluster) const { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mPositionCluster[romanPotId][planeId][cluster] : 0;}
inline double  StRpsPreCollection::positionRMSCluster(int romanPotId, int planeId, int cluster) const { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mPositionRMSCluster[romanPotId][planeId][cluster] : 0;}
inline short  StRpsPreCollection::lengthCluster(int romanPotId, int planeId, int cluster) const { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mLengthCluster[romanPotId][planeId][cluster] : 0;}
inline double StRpsPreCollection::energyCluster(int romanPotId, int planeId, int cluster) const { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mEnergyCluster[romanPotId][planeId][cluster] : 0;}
inline double StRpsPreCollection::xyCluster(int romanPotId, int planeId, int cluster) const  { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mXYCluster[romanPotId][planeId][cluster] : 0;}
inline unsigned char StRpsPreCollection::qualityCluster(int romanPotId, int planeId, int cluster) const   { return romanPotId < mNumberOfRomanPot && planeId < mNumberOfPlanes && cluster < mNumberOfClusters[romanPotId][planeId]? mQualityCluster[romanPotId][planeId][cluster] : 0;}

#endif

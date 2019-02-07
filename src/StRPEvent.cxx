
//_____________________________________________________________________________
//    Class for RP data
//    Author: Tomas Truhlar
//
//    RP event
//_____________________________________________________________________________

//root headers
#include "TClonesArray.h"
#include "TIterator.h"
#include "TParticle.h"

//local headers
/*
#include "StRpsPreCollection.h"
#include "StRpsPreTrack.h"
#include "StRpsPreTrackPoint.h"
*/
#include "StRpsCollection.h"
#include "StRpsRomanPot.h"
#include "StRpsPlane.h"
#include "StRpsCluster.h"
#include "StRpsTrack.h"
#include "StRpsTrackPoint.h"
#include "StRPEvent.h"

ClassImp(StRPEvent);

class StRpsCollection; 
class StRpsRomanPot; 
class StRpsPlane; 
class StRpsCluster; 
class StRpsTrack;
class StRpsTrackPoint;

/*
class StRpsPreCollection; 
class StRpsPreTrack; 
class StRpsPreTrackPoint; 

TClonesArray *StRPEvent::mgPreCollections = 0;
TClonesArray *StRPEvent::mgPreTrackPoints = 0;
TClonesArray *StRPEvent::mgPreTracks = 0;
*/


TClonesArray *StRPEvent::mgCollections = 0;
TClonesArray *StRPEvent::mgTrackPoints = 0;
TClonesArray *StRPEvent::mgTracks = 0;
TClonesArray *StRPEvent::mgRomanPots = 0;
TClonesArray *StRPEvent::mgPlanes = 0;
TClonesArray *StRPEvent::mgClusters = 0;



//_____________________________________________________________________________
StRPEvent::StRPEvent():
 // mPreCollections(0x0), mNPreCollections(0),
  mCollections(0x0), mNCollections(0),
 // mPreTrackPoints(0x0), mNPreTrackPoints(0),
 // mPreTracks(0x0), mNPreTracks(0),
  mTrackPoints(0x0), mNTrackPoints(0),
  mTracks(0x0), mNTracks(0),
  mRomanPots(0x0), mNRomanPots(0),
  mPlanes(0x0), mNPlanes(0),
  mClusters(0x0), mNClusters(0)
{
  //default constructor

  mTrgIDs.Set(0);

  if(!mgCollections) {
    mgCollections = new TClonesArray("StRpsCollection");
    mCollections = mgCollections;
    mCollections->SetOwner(kTRUE);
  }
/*
  if(!mgPreTrackPoints) {
    mgPreTrackPoints = new TClonesArray("StRpsPreTrackPoint");
    mPreTrackPoints = mgPreTrackPoints;
    mPreTrackPoints->SetOwner(kTRUE);
  }

  if(!mgPreTracks) {
    mgPreTracks = new TClonesArray("StRpsPreTrack");
    mPreTracks = mgPreTracks;
    mPreTracks->SetOwner(kTRUE);
  }

  if(!mgPreCollections) {
    mgPreCollections = new TClonesArray("StRpsPreCollection");
    mPreCollections = mgPreCollections;
    mPreCollections->SetOwner(kTRUE);
  }
*/
  if(!mgTrackPoints) {
    mgTrackPoints = new TClonesArray("StRpsTrackPoint");
    mTrackPoints = mgTrackPoints;
    mTrackPoints->SetOwner(kTRUE);
  }

  if(!mgTracks) {
    mgTracks = new TClonesArray("StRpsTrack");
    mTracks = mgTracks;
    mTracks->SetOwner(kTRUE);
  }

  if(!mgRomanPots) {
    mgRomanPots = new TClonesArray("StRpsRomanPot");
    mRomanPots = mgRomanPots;
    mRomanPots->SetOwner(kTRUE);
  }

  if(!mgPlanes) {
    mgPlanes = new TClonesArray("StRpsPlane");
    mPlanes = mgPlanes;
    mPlanes->SetOwner(kTRUE);
  }

  if(!mgClusters) {
    mgClusters = new TClonesArray("StRpsCluster");
    mClusters = mgClusters;
    mClusters->SetOwner(kTRUE);
  }


}//StRPEvent

//_____________________________________________________________________________
StRPEvent::~StRPEvent()
{
  //destructor

  if(mClusters) {delete mClusters; mClusters = 0x0;}
  if(mPlanes) {delete mPlanes; mPlanes = 0x0;}
  if(mRomanPots) {delete mRomanPots; mRomanPots = 0x0;}
  if(mTracks) {delete mTracks; mTracks = 0x0;}
  if(mTrackPoints) {delete mTrackPoints; mTrackPoints = 0x0;}
/*
  if(mPreTracks) {delete mPreTracks; mPreTracks = 0x0;}
  if(mPreTrackPoints) {delete mPreTrackPoints; mPreTrackPoints = 0x0;}
  if(mPreCollections) {delete mPreCollections; mPreCollections = 0x0;}
*/
  if(mCollections) {delete mCollections; mCollections = 0x0;}


}//~StRPEvent

//_____________________________________________________________________________
void StRPEvent::clearEvent()
{
  // clear event variables

  mTrgIDs.Set(0);
/*
  mPreCollections->Clear("C"); 
  mNPreCollections = 0;
  mPreTrackPoints->Clear("C"); 
  mNPreTrackPoints = 0;
  mPreTracks->Clear("C"); 
  mNPreTracks = 0;
 */ 
  mCollections->Clear("C"); 
  mNCollections = 0;
  mTrackPoints->Clear("C"); 
  mNTrackPoints = 0;
  mTracks->Clear("C"); 
  mNTracks = 0;
  mRomanPots->Clear("C"); 
  mNRomanPots = 0;
  mPlanes->Clear("C"); 
  mNPlanes = 0;
  mClusters->Clear("C"); 
  mNClusters = 0;

}//clearEvent

//_____________________________________________________________________________
void StRPEvent::addTriggerId(Int_t id) {
  //add fired trigger ID

  //position to put the ID
  Int_t pos = mTrgIDs.GetSize();

  //extend the array
  mTrgIDs.Set(pos+1);

  //put the ID
  mTrgIDs.AddAt(id, pos);

}//addTriggerId


//_____________________________________________________________________________
StUPCTrack *StRPEvent::addTrack()
{
  // construct new upc track

  return dynamic_cast<StRpsTrack*>( mRPTracks->ConstructedAt(mNTracks++) );

}//addTrack


//_____________________________________________________________________________
StRpsTrackPoint *StRPEvent::addTrackPoint()
{
  // construct new upc track

  return dynamic_cast<StRpsTrackPoint*>( mRPTrackPoints->ConstructedAt(mNTrackPoints++) );

}//addTrackPoint

//_____________________________________________________________________________
StRpsCluster *StRPEvent::addCluster()
{
  // construct new upc track

  return dynamic_cast<StRpsCluster*>( mClusters->ConstructedAt(mNClusters++) );

}//addCluster

//_____________________________________________________________________________
StRpsPlane *StRPEvent::addPlane()
{
  // construct new upc track

  return dynamic_cast<StRpsPlane*>( mPlanes->ConstructedAt(mNPlanes++) );

}//addPlane

//_____________________________________________________________________________
StRpsRomanPot *StRpsRomanPot::addRomanPot()
{
  // construct new upc track

  return dynamic_cast<StRpsRomanPot*>( mRomanPots->ConstructedAt(mNRomanPots++) );

}//addRomanPot

//_____________________________________________________________________________
StRpsCollection *StRPEvent::addCollection()
{
  // construct new upc track

  return dynamic_cast<StRpsCollection*>( mCollections->ConstructedAt(mNCollections++) );

}//addCollection
/*
//_____________________________________________________________________________
StRpsPreTrackPoint *StRPEvent::addPreTrackPoint()
{
  // construct new upc track

  return dynamic_cast<StRpsPreTrackPoint*>( mRPPreTrackPoints->ConstructedAt(mNPreTrackPoints++) );

}//addPreTrackPoint 

//_____________________________________________________________________________
StRpsPreCollection *StRPEvent::addPreCollection()
{
  // construct new upc track

  return dynamic_cast<StRpsPreCollection*>( mPreCollections->ConstructedAt(mNPreCollections++) );

}//addPreCollection

//_____________________________________________________________________________
StRpsPreTrack *StRPEvent::addPreTrack()
{
  // construct new upc track

  return dynamic_cast<StRpsPreTrack*>( mRPPreTracks->ConstructedAt(mNPreTracks++) );

}//addPreTrack
*/
//_____________________________________________________________________________
Bool_t StRPEvent::isTrigger(Int_t id) const
{
  //get fired trigger ID
  for(Int_t i=0; i<mTrgIDs.GetSize(); i++) {
    if( mTrgIDs.At(i) == id ) return kTRUE;
  }

  return kFALSE;

}//setTrigger

//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfTracks() const {

  //number of tracks in event

  if( !mRPTracks ) return 0;

  return mRPTracks->GetEntriesFast();

}//getNumberOfTracks

//_____________________________________________________________________________
StRpsTrack *StRPEvent::getTrack(Int_t iTrack) const
{
  // get RP track

  StRpsTrack *track = dynamic_cast<StRpsTrack*>( mRPTracks->At(iTrack) );
  if(track) track->setEvent( const_cast<StRPEvent*>(this) );

  return track;

}//getTrack
/*
//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfPreTracks() const {

  //number of Pretracks in event

  if( !mRPPreTracks ) return 0;

  return mRPPreTracks->GetEntriesFast();

}//getNumberOfPreTracks

//_____________________________________________________________________________
StRpsPreTrack *StRPEvent::getPreTrack(Int_t iTrack) const
{
  // get RP Pretrack

  StRpsPreTrack *track = dynamic_cast<StRpsPreTrack*>( mRPPreTracks->At(iTrack) );
  if(track) track->setEvent( const_cast<StRPEvent*>(this) );

  return track;

}//getPreTrack
*/
//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfTrackPoints() const {

  //number of trackPoints in event

  if( !mRPTrackPoints ) return 0;

  return mRPTrackPoints->GetEntriesFast();

}//getNumberOfTrackPoints

//_____________________________________________________________________________
StRpsTrackPoint *StRPEvent::getTrackPoint(Int_t iTrackPoint) const
{
  // get RP trackPoint

  StRpsTrackPoint *trackPoint = dynamic_cast<StRpsTrackPoint*>( mRPTrackPoints->At(iTrackPoint) );
  if(track) trackPoint->setEvent( const_cast<StRPEvent*>(this) );

  return trackPoint;

}//getTrackPoint
/*
//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfPreTrackPoints() const {

  //number of PretrackPoints in event

  if( !mRPPreTrackPoints ) return 0;

  return mRPPreTrackPoints->GetEntriesFast();

}//getNumberOfPreTrackPoints

//_____________________________________________________________________________
StRpsPreTrackPoint *StRPEvent::getPreTrackPoint(Int_t iTrackPoint) const
{
  // get RP PretrackPoint

  StRpsPreTrackPoint *trackPoint = dynamic_cast<StRpsPreTrackPoint*>( mRPPreTrackPoints->At(iTrackPoint) );
  if(trackPoint) trackPoint->setEvent( const_cast<StRPEvent*>(this) );

  return trackPoint;

}//getPreTrackPoint
*/

//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfClusters() const {

  //number of Clusters in event

  if( !mClusters ) return 0;

  return mClusters->GetEntriesFast();

}//getNumberOfClusters

//_____________________________________________________________________________
StRpsCluster *StRPEvent::getCluster(Int_t iCluster) const
{
  // get RP Cluster

  StRpsCluster *Cluster = dynamic_cast<StRpsCluster*>( mClusters->At(iCluster) );
  if(Cluster) Cluster->setEvent( const_cast<StRPEvent*>(this) );

  return Cluster;

}//getCluster


//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfPlanes() const {

  //number of Planes in event

  if( !mPlanes ) return 0;

  return mPlanes->GetEntriesFast();

}//getNumberOfPlanes

//_____________________________________________________________________________
StRpsPlane *StRPEvent::getPlane(Int_t iPlane) const
{
  // get RP Plane

  StRpsPlane *Plane = dynamic_cast<StRpsPlane*>( mPlanes->At(iPlane) );
  if(Plane) Plane->setEvent( const_cast<StRPEvent*>(this) );

  return Plane;

}//getPlane

//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfRomanPots() const {

  //number of RomanPot in event

  if( !mRomanPots ) return 0;

  return mRomanPots->GetEntriesFast();

}//getNumberOfRomanPots

//_____________________________________________________________________________
StRpsRomanPot *StRPEvent::getRomanPot(Int_t iRomanPot) const
{
  // get RP RomanPot

  StRpsRomanPot *RomanPot = dynamic_cast<StRpsRomanPot*>( mRomanPots->At(iRomanPot) );
  if(RomanPot) RomanPot->setEvent( const_cast<StRPEvent*>(this) );

  return RomanPot;

}//getRomanPot


//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfCollections() const {

  //number of mCollections in event

  if( !mCollections ) return 0;

  return mCollections->GetEntriesFast();

}//getNumberOfCollections

//_____________________________________________________________________________
StRpsCollection *StRPEvent::getCollection(Int_t iCollection) const
{
  // get RP Collection

  StRpsCollection *Collection = dynamic_cast<StRpsCollection*>( mCollections->At(iCollection) );
  if(Collection) Collection->setEvent( const_cast<StRPEvent*>(this) );

  return Collection;

}//getCollection

/*
//_____________________________________________________________________________
Int_t StRPEvent::getNumberOfPreCollections() const {

  //number of PreCollections in event

  if( !mPreCollections ) return 0;

  return mPreCollections->GetEntriesFast();

}//getNumberOfPreCollections

//_____________________________________________________________________________
StRpsPreCollection *StRPEvent::getPreCollection(Int_t iPreCollection) const
{
  // get RP PreCollection

  StRpsPreCollection *PreCollection = dynamic_cast<StRpsPreCollection*>( mPreCollections->At(iPreCollection) );
  if(PreCollection) PreCollection->setEvent( const_cast<StRPEvent*>(this) );

  return PreCollection;

}//getPreCollection
*/













#ifndef StRPEvent_h
#define StRPEvent_h

//_____________________________________________________________________________
//    Class for UPC data
//    Author: Truhlar Tomas
//_____________________________________________________________________________


class StRpsPreCollection; 
class StRpsPreTrack; 
class StRpsPreTrackPoint; 
class StRpsCollection; 
class StRpsRomanPot; 
class StRpsPlane; 
class StRpsCluster; 
class StRpsTrack;
class StRpsTrackPoint;

class TClonesArray;
class TIterator;
class TParticle;

#include "TArrayI.h"

class StRPEvent
{

public:

  StRPEvent();
  virtual ~StRPEvent(); 

  void clearEvent(); 

   void addTriggerId(Int_t id);


  //setters

  StRpsPreCollection *addPreCollection(); 
  StRpsPreTrack *addPreTrack(); 
  StRpsPreTrackPoint *addPreTrackPoint(); 
  StRpsCollection *addCollection(); 
  StRpsRomanPot *addRomanPot(); 
  StRpsPlane *addPlane(); 
  StRpsCluster *addCluster(); 
  StRpsTrack *addTrack();
  StRpsTrackPoint *addTrackPoint();

  //getters
  Bool_t isTrigger(Int_t id) const;

  Int_t getNumberOfTracks() const;
  StRpsTrack *getTrack(Int_t iTrack) const;
  Int_t getNumberOfTrackPoints() const;
  StRpsTrackPoint *getTrackPoint(Int_t iTrackPoint) const;
/*
  Int_t getNumberOfPreTracks() const;
  StRpsPreTrack *getPreTrack(Int_t iTrack) const;

  Int_t getNumberOfPreTrackPoints() const;
  StRpsPreTrackPoint *getPreTrackPoint(Int_t iTrackPoint) const;

  Int_t getNumberOfPreCollections() const;
  StRpsPreCollection *getPreCollection(Int_t iPreCollection) const;
*/
  Int_t getNumberOfClusters() const;
  StRpsCluster *getCluster(Int_t iCluster) const;

  Int_t getNumberOfPlanes() const;
  StRpsPlane *getPlane(Int_t iPlane) const;

  Int_t getNumberOfRomanPots() const;
  StRpsRomanPot *getRomanPot(Int_t iRomanPot) const;

  Int_t getNumberOfCollections() const;
  StRpsCollection *getCollection(Int_t iCollection) const;

private:

  StRPEvent (const StRPEvent &o); 
  StRPEvent &operator=(const StRPEvent &o); 

  TArrayI mTrgIDs; // fired trigger IDs

  static TClonesArray *mgTracks; // array of upc tracks
  TClonesArray *mTracks; //-> array of upc tracks
  Int_t mNTracks; //! number of upc tracks in event, local use when filling

  static TClonesArray *mgTrackPoints; // array of upc tracks
  TClonesArray *mTrackPoints; //-> array of upc tracks
  Int_t mNTrackPoints; //! number of upc tracks in event, local use when filling
/*
  static TClonesArray *mgRPPreTracks; // array of upc tracks
  TClonesArray *mRPPreTracks; //-> array of upc tracks
  Int_t mNPreTracks; //! number of upc tracks in event, local use when filling

  static TClonesArray *mgRPPreTrackPoints; // array of upc tracks
  TClonesArray *mRPPreTrackPoints; //-> array of upc tracks
  Int_t mNPreTrackPoints; //! number of upc tracks in event, local use when filling  

  static TClonesArray *mgPreCollections; // array of BEMC clusters
  TClonesArray *mPreCollections; //-> array of BEMC clusters
  Int_t mNPreCollections; //! number of BEMC clusters written in event, local use when filling
*/
  static TClonesArray *mgCollections; // array of UPC vertices
  TClonesArray *mCollections; //-> array of UPC vertices
  Int_t mNCollections; //! number of vertices written in event, local use when filling

  static TClonesArray *mgRomanPots; // array of MC particles
  TClonesArray *mRomanPots; // array of MC particles
  Int_t mNRomanPots; //! number of mc particles in event, local use when filling

  static TClonesArray *mgClusters; // array of MC particles
  TClonesArray *mClusters; // array of MC particles
  Int_t mNClusters; //! number of mc particles in event, local use when filling

  static TClonesArray *mgPlanes; // array of MC particles
  TClonesArray *mPlanes; // array of MC particles
  Int_t mNPlanes; //! number of mc particles in event, local use when filling

  ClassDef(StRPEvent, 2);
};

#endif














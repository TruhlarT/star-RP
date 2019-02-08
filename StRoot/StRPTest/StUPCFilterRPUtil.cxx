
//_____________________________________________________________________________
//
//    Utility class for RP in UPC filter maker
//    Author: Truhlar Tomas
//
//_____________________________________________________________________________
//c++ headers
#include "string.h"
#include <vector>

//root headers
#include "TObjArray.h"
#include "TClonesArray.h"

//StRoot headers
#include "StMuDSTMaker/COMMON/StMuDst.h"
#include "StMuDSTMaker/COMMON/StMuRpsCollection.h"
#include "StMuDSTMaker/COMMON/StMuRpsTrackPoint.h"
#include "StMuDSTMaker/COMMON/StMuRpsTrack.h"


//local headers
#include "StRPEvent.h"
#include "StUPCRpsCollection.h"
#include "StUPCRpsRomanPot.h"
#include "StUPCRpsPlane.h"
#include "StUPCRpsCluster.h"
#include "StUPCRpsTrackPoint.h"
#include "StUPCRpsTrack.h"

#include "StUPCFilterRPUtil.h"


//_____________________________________________________________________________
StUPCFilterRPUtil::StUPCFilterRPUtil() {
  //constructor

}//StUPCFilterRPUtil

//_____________________________________________________________________________
void StUPCFilterRPUtil::processEvent(StRPEvent *rpEvt, StMuDst *mMuDst) {
//_________________MY Part_______________________________//
// I will nou use Prethinks? 



  StMuRpsCollection *collection = mMuDst->RpsCollection();
  StUPCRpsCollection *rpCollection = rpEvt->addCollection(); 
  rpCollection->setSiliconBunch(collection->siliconBunch());

  StUPCRpsRomanPot *rpRomanPot = rpEvt->addRomanPot(); 
  for(Int_t iRomanPotId=0; iRomanPotId < collection->numberOfRomanPots(); ++iRomanPotId){

    rpRomanPot->setStatus(collection->status(iRomanPotId));
    rpRomanPot->setAdc(collection->adc(iRomanPotId, 0), collection->adc(iRomanPotId, 1));
    rpRomanPot->setTac(collection->tac(iRomanPotId, 0), collection->tac(iRomanPotId, 1)); 

    for(Int_t iPlaneId=0; iPlaneId < collection->numberOfPlanes(); ++iPlaneId){
      StUPCRpsPlane *rpPlane = rpEvt->addPlane(); 
      rpPlane->setOffset(collection->offsetPlane(iRomanPotId, iPlaneId));
      rpPlane->setZ(collection->zPlane(iRomanPotId, iPlaneId));  
      rpPlane->setAngle(collection->anglePlane(iRomanPotId, iPlaneId));  
      rpPlane->setOrientation(collection->orientationPlane(iRomanPotId, iPlaneId));  
      rpPlane->setStatus(collection->statusPlane(iRomanPotId, iPlaneId));

      for(Int_t iCluster=0; iCluster < collection->numberOfClusters(iRomanPotId, iPlaneId); ++iCluster){
        StUPCRpsCluster *rpCluster = rpEvt->addCluster(); 
        rpCluster->setPosition(collection->positionCluster(iRomanPotId, iPlaneId, iCluster));
        rpCluster->setPositionRMS(collection->positionRMSCluster(iRomanPotId, iPlaneId, iCluster)); 
        rpCluster->setLength(collection->lengthCluster(iRomanPotId, iPlaneId, iCluster)); 
        rpCluster->setEnergy(collection->energyCluster(iRomanPotId, iPlaneId, iCluster)); 
        rpCluster->setXY(collection->xyCluster(iRomanPotId, iPlaneId, iCluster)); 
        rpCluster->setQuality(collection->qualityCluster(iRomanPotId, iPlaneId, iCluster));
        rpPlane->addCluster(rpCluster); 
      }

    for(Int_t iTrackPoint=0; iTrackPoint < collection->numberOfTrackPoints(); ++iTrackPoint){ 
      StMuRpsTrackPoint *trackPoint = collection->trackPoint(iTrackPoint);
      StUPCRpsTrackPoint *rpTrackPoint = rpEvt->addTrackPoint();
      rpTrackPoint->setPosition(trackPoint->positionVec());
      rpTrackPoint->setRpId(trackPoint->rpId());
      rpTrackPoint->setClusterId(trackPoint->clusterId(iPlaneId), iPlaneId);
     // rpTrackPoint->setTime(trackPoint->time(1), 1); // trackPoint->time(pmtId) = co je pmtID????
     // rpTrackPoint->setQuality(trackPoint->quality()); // problem enum ma ruzny jmena

      rpCollection->addTrackPoint(rpTrackPoint); 
    }
    }
  }

  for(Int_t iTrack=0; iTrack < collection->numberOfTracks(); ++iTrack){
    StMuRpsTrack *track = collection->track(iTrack);
    StUPCRpsTrack *rpTrack = rpEvt->addTrack();
    for(Int_t iTrackPoint=0; iTrackPoint < 2; ++iTrackPoint){
   //   StMuRpsTrackPoint *trackPoint = track->trackPoint(iTrackPoint); // invalid conversion from 'const StMuRpsTrackPoint*' to 'StMuRpsTrackPoint*'
     // StUPCRpsTrackPoint *rpTrackPoint = rpEvt->addTrackPoint();
     // rpTrackPoint->setPosition(trackPoint->positionVec());
     // rpTrackPoint->setRpId(trackPoint->rpId());
     // rpTrackPoint->setClusterId(trackPoint->clusterId(iPlaneId), iPlaneId); // Problem nemam iPlaneId
     // rpTrackPoint->setTime(trackPoint->time(), 1); // (double timeVal, unsigned int pmtId)
     // rpTrackPoint->setQuality(trackPoint->quality());

     // rpTrack->setTrackPoint(rpTrackPoint, iTrackPoint);
    }
    //rpTrack->setTrackPoint(track->trackPoint(0), 0); // first of mNumberOfStationsInBranch = 2
    //rpTrack->setTrackPoint(track->trackPoint(1), 1); // second of mNumberOfStationsInBranch = 2
    rpTrack->setP(track->pVec()); 
    rpTrack->setBranch(track->branch()); 
    //rpTrack->setType(track->type());  // problem enum ma ruzny jmena
    rpCollection->addTrack(rpTrack); 
  }


/*
  StRpsPreCollection *rpPreCollection = rpEvt->addPreCollection(); 
    rpPreCollection->setPosition(const TVector3&);
    rpPreCollection->setRpId(int);
    rpPreCollection->setClusterId(int, unsigned int);
    rpPreCollection->setTime(double, unsigned int);
    rpPreCollection->setQuality(StRpsTrackPointQuality);

  StRpsPreTrack *rpPreTrack  = rpEvt->addPreTrack(); 
    rpPreTrack->setTrackPoint( StRpsPreTrackPoint*, unsigned int);
    rpPreTrack->setP(const TVector3&);
    rpPreTrack->setBranc// in muDsth(int);
    rpPreTrack->setType(StRpsPreTrackType type);

  StRpsPreTrackPoint *rpPreTrackPoint = rpEvt->addPreTrackPoint(); 
    rpPreTrackPoint->setPosition(const TVector3&);
    rpPreTrackPoint->setRpId(Int_t);
    rpPreTrackPoint->setClusterId(Int_t, unsigned int);
    rpPreTrackPoint->setQuality(StRpsPreTrackPointQuality quality);
    rpPreTrackPoint->setTime(double, unsigned int);
*/

}//processEvent


























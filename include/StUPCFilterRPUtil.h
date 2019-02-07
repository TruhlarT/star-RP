#ifndef StUPCFilterRPUtil_h
#define StUPCFilterRPUtil_h

class StUPCFilterRPUtil {

public:

  StUPCFilterRPUtil();
  virtual ~StUPCFilterRPUtil() {}

  void processEvent(StRPEvent *rpEvt, StMuDst *mMuDst);

private:

  StUPCFilterRPUtil(const StUPCFilterRPUtil &o); // not implemented
  StUPCFilterRPUtil &operator=(const StUPCFilterRPUtil &o); // not implemented

};

#endif


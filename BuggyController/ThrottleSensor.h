#ifndef ThrottleSensor_h
#define ThrottleSensor_h

#include "VoltageSensor.h"

typedef enum {TH_ZERO, TH_NORMAL, TH_BOOST}         throttleStatusType;
typedef struct throttleStatusNode {
    double              threshold; 
    throttleStatusType  statusVal;
} throttleStatusNode;

// #define THROTTLE_STATUS_NODES 2

class ThrottleSensor: public NormalizedVoltageSensor
{
public:
    ThrottleSensor();
    void                    setStatusBounds(double throttleZero=0.0, double throttleBoost=1.0);
    throttleStatusType      getStatus();
    void                    initSmoother();
    // void                    init();
    // DEBUG
    int                     snprintNormalized(char* buffer, int charsRemaining);
    // int                     snprintValLabel(char* buffer, int charsRemaining);
    int                     snprintStatusNode(char* buffer, int charsRemaining, throttleStatusNode node);
    int                     snprintStatusTable(char* buffer, int charsRemaining);
    int                     snprintReadings(char* buffer, int charsRemaining);
    int                     snprintStatusString(char* buffer, int charsRemaining, throttleStatusType statusVal);
protected:
    const static int        _statusNodes = 2;
    throttleStatusNode      _statusTable[_statusNodes];
};

#endif
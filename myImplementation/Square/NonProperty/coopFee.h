#ifndef __COOPFEE_H__
#define __COOPFEE_H__

class CoopFee: public NonProperty{
public:
	CoopFee::CoopFee(Board *theBoard, TextDisplay *);
	void action();
};

#endif
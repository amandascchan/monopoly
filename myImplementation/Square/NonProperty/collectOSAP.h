#ifndef __COLLECTOSAP_H__
#define __COLLECTOSAP_H__

class CollectOSAP: public NonProperty{
public:
	CollectOSAP(Board *theBoard, Square *prevSquare, Square *nextSquare);
	void action();
};

#endif

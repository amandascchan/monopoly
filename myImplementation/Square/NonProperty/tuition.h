#ifndef __TUITION_H__
#define __TUITION_H__

class Tuition: public NonProperty{
public:
	Tuition::Tuition(Board *, TextDisplay *);
	void action();
};

#endif
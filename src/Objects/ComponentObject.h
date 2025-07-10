/*
fILE DESCRIPTION HERE
*/

#ifndef COMPONENTOBJECT_H_
#define COMPONENTOBJECT_H_

class ComponentObject
{
protected:
    float nextXmove;
    float nextYmove;
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Shutdown(void);

    float get_nextXmove(void) { return nextXmove; }
    void set_nextXmove(float x) { nextXmove = x; }
    float get_nextYmove(void) { return nextYmove; }
    void set_nextYmove(float y) { nextYmove = y; }
};

#endif

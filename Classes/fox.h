#ifndef __fox_H__
#define __fox_H__
#include "InputEvents.h"
#include "cocos2d.h"

class Fox : public cocos2d::Layer, public InputEvents
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	Sprite * fox(int x, int y);
	void foxDraw(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(Fox);
private:
	Size visibleSize;
};

#endif // __HELLOWORLD_SCENE_H__

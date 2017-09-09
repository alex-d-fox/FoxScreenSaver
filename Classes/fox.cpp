#include "fox.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Fox::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Fox::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Fox::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	visibleSize = Director::getInstance()->getVisibleSize();

	auto keyListener = EventListenerKeyboard::create();
	auto mouseListener = EventListenerMouse::create();
	
	keyListener->onKeyPressed = CC_CALLBACK_0(InputEvents::exitGame, this);
	mouseListener->onMouseMove = CC_CALLBACK_0(InputEvents::exitGame, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	Fox::foxDraw(0.0f);

	this->schedule(schedule_selector(Fox::foxDraw), 3.0f);
	
	this->scheduleUpdate();
    
	return true;
}

Sprite * Fox::fox(int x, int y) {
	auto particles = ParticleFire::create();
	auto foxSprite = Sprite::create("fox.png");
	auto tailSprite = Sprite::create("tail1.png");
	foxSprite->setPosition(x, y);
	tailSprite->setPosition(75,15);
	particles->setPosition(115, 20);
	particles->setScale(0.5f);
	Vector<SpriteFrame*> animFrames(15);
	char str[10] = { 0 };
	for (int i = 0; i < 12; i++)
	{
		int r = random(1, 5);
		sprintf(str, "tail%i.png", r);
		auto frame = SpriteFrame::create(str, Rect(0, 0, 38, 19));
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);
	auto animate = Animate::create(animation);
	tailSprite->runAction(animate);
	foxSprite->addChild(particles);
	foxSprite->addChild(tailSprite);
	return foxSprite;
}

void Fox::foxDraw(float dt) {
	removeAllChildren();
	for (int i = 0; i <= 15; i++) {
		Sprite * foxSprite = fox(random(0, int(visibleSize.width)), random(0, int(visibleSize.height)));
		addChild(foxSprite);
	}
}
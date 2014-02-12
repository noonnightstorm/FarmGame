#include "AppDelegate.h"

#include "cocos2d.h"
#include "StartScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	    CCDirector* pDirector = CCDirector::sharedDirector();
	    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
	    CCSize designSize = CCSizeMake(480,320);
	    std::vector<std::string> searchPaths;


	    if(screenSize.height>320) {
	    	searchPaths.push_back("HD");
	    	searchPaths.push_back("SD");
	    	pDirector->setContentScaleFactor(640.0f/designSize.height);
	    }
	    else {
	    	searchPaths.push_back("SD");
	    	pDirector->setContentScaleFactor(320.0f/designSize.height);
	    }

	    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

	    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);


	    // turn on display FPS
	    pDirector->setDisplayStats(false);

	    // set FPS. the default value is 1.0/60 if you don't call this
	    pDirector->setAnimationInterval(1.0 / 60);

	    // create a scene. it's an autorelease object
	    CCScene* pScene = StartScene::create();

	    // run
	    pDirector->runWithScene(pScene);

	    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

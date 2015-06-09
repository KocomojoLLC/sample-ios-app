
#Kocomojo iOS SDK

Kocomojo is a location-based marketing service which supports iBeacons

##Getting Started
###Step 1: Install the library
**CocoaPods**
CocoaPods is preferred way to install Kocomojo iOS SDK. Install [CocoaPods](https://cocoapods.org/) and add following lines to your Podfile:

	platform :ios, '7.0'
    pod 'KocomojoSDK', '~> 0.9'

Run `pod install` and don't forget to use .xcworkspace instead of .xcodeproj.

**Manual installation**

1. Download [KocomojoSDK-0.9.0.tgz](http://assets.kocomojo.net/sdk/KocomojoSDK-0.9.0.tgz).
1. Unarchive the file you downloaded.
1. In Xcode, with your project open, click on 'File' then 'Add files to "Project"...'.
1. Select `KocomojoSDK.framework` in the directory you just unarchived.
1. Make sure 'Copy items if needed' is checked.
1. Click 'Add'.
1. Install dependencies:
	- [CocoaLumberjack](https://github.com/CocoaLumberjack/CocoaLumberjack)
	- [AFNetworking](https://github.com/AFNetworking/AFNetworking)
1. Add `CoreLocation` framework to the project

### Step 2: Insert API Key

1. Open [Kocomojo Dashboard](https://admin.kocomojo.net) and sign-in using your username and password.
2. Click 'MOBILE APPS' in the sideboard.
3. Select an app in the list.
3. Click 'Show' button.
4. Enter username and password and click 'SIGN IN' button.
5. Copy API Key displayed
6. Insert following lines into `AppDelegate.m`, replacing '<< API KEY >>' with the copied API Key

```
// AppDelegate.m

#import "AppDelegate.h"
#import <KocomojoSDK/KocomojoSDK.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [[KocomojoManager sharedManager] setApiKey:@"<< API KEY >>"];
  [[KocomojoManager sharedManager] startTracking];
  return YES;
}
@end
```

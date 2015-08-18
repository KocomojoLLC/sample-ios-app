
#Kocomojo iOS SDK

Kocomojo is a location-based marketing service.

## Getting Started
### Install the library
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

### Insert API Key

1. Open [Kocomojo Dashboard](https://admin.kocomojo.net/admin/index.html#/dashboard) and sign-in using your username and password.
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

### Enable location tracking
For iOS 8+ add the following entries to Info.plist:
```
<key>NSLocationWhenInUseUsageDescription</key>
<string>Please enable location services</string>
<key>NSLocationAlwaysUsageDescription</key>
<string>Please enable location services</string>
```

### Implement nearby promotions view
To create a nearby promotions view do the following:

1. Create a new UITableViewController-based class.
2. Add `NSArray *_promotions`  to the implementation ivars:
    ```
@implementation NearbyPromotionViewController {
        NSArray *_promotions;
}
    ```
    
3. Implement delegate methods as followed:
    ```
- (void)viewWillAppear:(BOOL)animated {
        [[KocomojoManager sharedManager] retrieveNearbyPromotions:^(NSArray *promotions, NSError *error) {
            _promotions = promotions;
            [self.tableView reloadData];
        }];
    };

    - (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
        return [_promotions count];
    }

    - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
        KMPromotion *promotion = _promotions[indexPath.row];
    
        cell.textLabel.text = promotion.title;
        cell.detailTextLabel.text = promotion.tagline;
    
        return cell;
    }

    ```

To test the code you should configure new promotion using Kocomojo admin dashboard. If the beacon is in sight or you are in the geofence borders promotion should appear in the list.

### Implement promotion view

1. Create a new UIViewController-based class.
2. Add `@property KMPromotion *promotion;` to the class interface.
3. Create `UILabel *` objects for promotion title, description and `UIImageView *` for the promotion image.
4. Bind promotion fields to the labels and the image view in `viewWillAppear:` method.
5. Add `UIButton *` for the check-in action and bind it to the handler:

    ```
    - (IBAction)checkInButtonTouched:(id)sender {
        [[KocomojoManager sharedManager] checkIn:_promotion completion:^(KMPromotionState *state, NSError *error) {
            if (state.reward) {
                // go to reward view
            } else {
                // close promotion view
            }
        }];
    }
    ```
1. Show promotion view when tapping on promotion in the nearby promotions table view. 
    If using segues create a segue in storyboard from the table view cell to a promotion view controller and insert the following snippet into a nearby promotions view controller replacing segue identifier.

    ```
    - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
        if ([segue.identifier isEqualToString:@"<<Promotion segue identifier>>"]) {
            KMPromotion *promotion = _promotions[[self.tableView indexPathForSelectedRow].row];
            [segue.destinationViewController setPromotion:promotion];
        }
    }

    ```

Test check-in action by tapping the button. If all promotion criteria are valid you should receive an updated `KMPromotionState *` with incremented count. If there are enough check-ins for the reward, then the `reward` property will be equal to `YES`.

### Implement reward view

1. Create a new UIViewController-based class.
2. Add `@property KMReward *reward;` to the class interface.
3. Create `UILabel *` objects for reward title, description and `UIImageView *` for the reward image.
4. Bind reward fields to the labels and the image view in `viewWillAppear:` method.
5. Show reward view when promotion view controller check-in completion callback called with promotion state reward equal to `YES`.

    ```
    - (IBAction)checkInButtonTouched:(id)sender {
        [[KocomojoManager sharedManager] checkIn:_promotion completion:^(KMPromotionState *state, NSError *error) {
            if (state.reward) {
                [self performSegueWithIdentifier:@"<<Reward segue identifier>>" sender:self];
            } 
            ...
        }];
    }

    - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
        if ([segue.identifier isEqualToString:@"<<Reward segue identifier>>"]) {
            [segue.destinationViewController setReward:_promotion.reward];
        }
    }

    ```
    
### Sample application
Sample application is available at https://github.com/KocomojoLLC/sample-ios-app.
    

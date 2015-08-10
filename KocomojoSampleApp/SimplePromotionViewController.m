//
//  SimplePromotionViewController.m
//  KocomojoSampleApp
//
//  Distribution, publication or any other public use or commercial exploitation is prohibited.
//  Copyright 2015 Kocomojo, LLC.
//

#import "SimplePromotionViewController.h"

#import <KocomojoSDK/KocomojoSDK.h>
#import <AFNetworking/UIImageView+AFNetworking.h>

@implementation SimplePromotionViewController {
    __weak IBOutlet UIImageView *_topImageView;
    __weak IBOutlet UILabel *_titleLabel;
    __weak IBOutlet UILabel *_descriptionLabel;
    __weak IBOutlet UIButton *_checkInButton;
    __weak IBOutlet UIActivityIndicatorView *_activityIndicator;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    if (_promotion.imageUrl) {
        [_topImageView setImageWithURL: [NSURL URLWithString:_promotion.imageUrl]];
    }
    
    _titleLabel.text = _promotion.title;
    _descriptionLabel.text = _promotion.descriptionText;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)checkInButtonTouched:(id)sender {
    _checkInButton.enabled = NO;
    [_activityIndicator startAnimating];
    
    [[KocomojoManager sharedManager] checkIn:_promotion completion:^(KMPromotionState *state, NSError *error) {
        _checkInButton.enabled = YES;
        [_activityIndicator stopAnimating];

        if (state.reward) {
            [self performSegueWithIdentifier:@"RewardSegue" sender:self];
        } else {
            [self performSegueWithIdentifier:@"UnwindToParentSegue" sender:self];
        }
    }];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"RewardSegue"]) {
        [segue.destinationViewController setPromotion:_promotion];
    }
}

@end

//
//  SimplePromotionRewardViewController.m
//  KocomojoSampleApp
//
//  Distribution, publication or any other public use or commercial exploitation is prohibited.
//  Copyright 2015 Kocomojo, LLC.
//

#import "SimplePromotionRewardViewController.h"

#import <KocomojoSDK/KocomojoSDK.h>
#import <AFNetworking/UIImageView+AFNetworking.h>

@implementation SimplePromotionRewardViewController {
    __weak IBOutlet UIImageView *_topImageView;
    __weak IBOutlet UILabel *_titleLabel;
    __weak IBOutlet UILabel *_descriptionLabel;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    if (_promotion.reward.imageUrl != (id)[NSNull null]) {
        [_topImageView setImageWithURL: [NSURL URLWithString:_promotion.reward.imageUrl]];
    }
    
    if (_promotion.reward.header != (id)[NSNull null]) {
        _titleLabel.text = _promotion.reward.header;
    }
    
    if (_promotion.reward.text != (id)[NSNull null]) {
        _descriptionLabel.text = _promotion.reward.text;
    }
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

@end

//
//  TSTAlertViewResponder.m
//  TSTAlertView
//
//  Created by Diogo Autilio on 9/26/14.
//  Copyright (c) 2014-2016 AnyKey Entertainment. All rights reserved.
//

#import "TSTAlertViewResponder.h"

@interface TSTAlertViewResponder ()

@property TSTAlertView *alertview;

@end

@implementation TSTAlertViewResponder

//
//// Allow alerts to be closed/renamed in a chainable manner
//// Example: TSTAlertView().showSuccess(self, title: "Test", subTitle: "Value").close()

// Initialisation and Title/Subtitle/Close functions
- (instancetype)init:(TSTAlertView *)alertview
{
    self.alertview = alertview;
    return self;
}

- (void)setTitletitle:(NSString *)title
{
    self.alertview.labelTitle.text = title;
}

- (void)setSubTitle:(NSString *)subTitle
{
    self.alertview.viewText.text = subTitle;
}

- (void)close
{
    [self.alertview hideView];
}

@end

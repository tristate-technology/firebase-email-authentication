//
//  TSTAlertViewResponder.h
//  TSTAlertView
//
//  Created by Diogo Autilio on 9/26/14.
//  Copyright (c) 2014-2016 AnyKey Entertainment. All rights reserved.
//

#if defined(__has_feature) && __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
#import "TSTAlertView.h"

@interface TSTAlertViewResponder : NSObject

/** TODO
 *
 * TODO
 */
- (instancetype)init:(TSTAlertView *)alertview;

/** TODO
 *
 * TODO
 */
- (void)close;

@end

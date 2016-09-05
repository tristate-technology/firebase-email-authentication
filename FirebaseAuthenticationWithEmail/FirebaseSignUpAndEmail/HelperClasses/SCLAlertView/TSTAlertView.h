//
//  TSTAlertView.h
//  TSTAlertView
//
//  Created by Diogo Autilio on 9/26/14.
//  Copyright (c) 2014-2016 AnyKey Entertainment. All rights reserved.
//

#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif
#import "TSTButton.h"
#import "TSTTextView.h"
#import "TSTSwitchView.h"

typedef NSAttributedString* (^TSTAttributedFormatBlock)(NSString *value);
typedef void (^TSTDismissBlock)(void);
typedef void (^TSTForceHideBlock)(void);

@interface TSTAlertView : UIViewController 

/** Alert Styles
 *
 * Set TSTAlertView Style
 */
typedef NS_ENUM(NSInteger, TSTAlertViewStyle)
{
    Success,
    Error,
    Notice,
    Warning,
    Info,
    Edit,
    Waiting,
    Question,
    Custom
};

/** Alert hide animation styles
 *
 * Set TSTAlertView hide animation type.
 */
typedef NS_ENUM(NSInteger, TSTAlertViewHideAnimation)
{
    FadeOut,
    SlideOutToBottom,
    SlideOutToTop,
    SlideOutToLeft,
    SlideOutToRight,
    SlideOutToCenter,
    SlideOutFromCenter
};

/** Alert show animation styles
 *
 * Set TSTAlertView show animation type.
 */
typedef NS_ENUM(NSInteger, TSTAlertViewShowAnimation)
{
    FadeIn,
    SlideInFromBottom,
    SlideInFromTop,
    SlideInFromLeft,
    SlideInFromRight,
    SlideInFromCenter,
    SlideInToCenter
};

/** Alert background styles
 *
 * Set TSTAlertView background type.
 */
typedef NS_ENUM(NSInteger, TSTAlertViewBackground)
{
    Shadow,
    Blur,
    Transparent
};

/** Content view corner radius
 *
 * A float value that replaces the standard content viuew corner radius.
 */
@property CGFloat cornerRadius;

/** Tint top circle
 *
 * A boolean value that determines whether to tint the TSTAlertView top circle.
 * (Default: YES)
 */
@property BOOL tintTopCircle;

/** Use larger icon
 *
 * A boolean value that determines whether to make the TSTAlertView top circle icon larger.
 * (Default: NO)
 */
@property BOOL useLargerIcon;
    
/** Title Label
 *
 * The text displayed as title.
 */
@property UILabel *labelTitle;

/** Text view with the body message
 *
 * Holds the textview.
 */
@property UITextView *viewText;

/** Activity Indicator
 *
 * Holds the activityIndicator.
 */
@property UIActivityIndicatorView *activityIndicatorView;

/** Dismiss on tap outside
 *
 * A boolean value that determines whether to dismiss when tapping outside the TSTAlertView.
 * (Default: NO)
 */
@property (nonatomic, assign) BOOL shouldDismissOnTapOutside;

/** Sound URL
 *
 * Holds the sound NSURL path.
 */
@property (nonatomic, strong) NSURL *soundURL;

/** Set text attributed format block
 *
 * Holds the attributed string.
 */
@property (nonatomic, copy) TSTAttributedFormatBlock attributedFormatBlock;

/** Set Complete button format block.
 *
 * Holds the button format block.
 * Support keys : backgroundColor, borderWidth, borderColor, textColor
 */
@property (nonatomic, copy) CompleteButtonFormatBlock completeButtonFormatBlock;

/** Set button format block.
 *
 * Holds the button format block.
 * Support keys : backgroundColor, borderWidth, borderColor, textColor
 */
@property (nonatomic, copy) ButtonFormatBlock buttonFormatBlock;

/** Set force hide block.
 *
 * When set force hideview method invocation.
 */
@property (nonatomic, copy) TSTForceHideBlock forceHideBlock;

/** Hide animation type
 *
 * Holds the hide animation type.
 * (Default: FadeOut)
 */
@property (nonatomic) TSTAlertViewHideAnimation hideAnimationType;

/** Show animation type
 *
 * Holds the show animation type.
 * (Default: SlideInFromTop)
 */
@property (nonatomic) TSTAlertViewShowAnimation showAnimationType;

/** Set TSTAlertView background type.
 *
 * TSTAlertView background type.
 * (Default: Shadow)
 */
@property (nonatomic) TSTAlertViewBackground backgroundType;

/** Set custom color to TSTAlertView.
 *
 * TSTAlertView custom color.
 * (Buttons, top circle and borders)
 */
@property (nonatomic, strong) UIColor *customViewColor;

/** Set custom color to TSTAlertView background.
 *
 * TSTAlertView background custom color.
 */
@property (nonatomic, strong) UIColor *backgroundViewColor;

/** Set custom tint color for icon image.
 *
 * TSTAlertView icon tint color
 */
@property (nonatomic, strong) UIColor *iconTintColor;

/** Set custom circle icon height.
 *
 * Circle icon height
 */
@property (nonatomic) CGFloat circleIconHeight;

/** Set TSTAlertView extension bounds.
 *
 * Set new bounds (EXTENSION ONLY)
 */
@property (nonatomic) CGRect extensionBounds;

/** Set status bar hidden.
 *
 * Status bar hidden
 */
@property (nonatomic) BOOL statusBarHidden;

/** Set status bar style.
 *
 * Status bar style
 */
@property (nonatomic) UIStatusBarStyle statusBarStyle;

/** Initialize TSTAlertView using a new window.
 *
 * Init with new window
 */
- (instancetype)initWithNewWindow;

/** Initialize TSTAlertView using a new window.
 *
 * Init with new window with custom width
 */
- (instancetype)initWithNewWindowWidth:(CGFloat)windowWidth;

/** Warns that alerts is gone
 *
 * Warns that alerts is gone using block
 */
- (void)alertIsDismissed:(TSTDismissBlock)dismissBlock;

/** Hide TSTAlertView
 *
 * Hide TSTAlertView using animation and removing from super view.
 */
- (void)hideView;

/** TSTAlertView visibility
 *
 * Returns if the alert is visible or not.
 */
- (BOOL)isVisible;

/** Remove Top Circle
 *
 * Remove top circle from TSTAlertView.
 */
- (void)removeTopCircle;

/** Add a custom UIView
 *
 * @param customView UIView object to be added above the first TSTButton.
 */
- (UIView *)addCustomView:(UIView *)customView;

/** Add Text Field
 *
 * @param title The text displayed on the textfield.
 */
- (TSTTextView *)addTextField:(NSString *)title;

/** Add a custom Text Field
 *
 * @param textField The custom textfield provided by the programmer.
 */
- (void)addCustomTextField:(UITextField *)textField;

/** Add a switch view
 *
 * @param label The label displayed for the switch.
 */
- (TSTSwitchView *)addSwitchViewWithLabel:(NSString *)label;

/** Add Timer Display
 *
 * @param buttonIndex The index of the button to add the timer display to.
 * @param reverse Convert timer to countdown.
 */
- (void)addTimerToButtonIndex:(NSInteger)buttonIndex reverse:(BOOL)reverse;

/** Set Title font family and size
 *
 * @param titleFontFamily The family name used to displayed the title.
 * @param size Font size.
 */
- (void)setTitleFontFamily:(NSString *)titleFontFamily withSize:(CGFloat)size;

/** Set Text field font family and size
 *
 * @param bodyTextFontFamily The family name used to displayed the text field.
 * @param size Font size.
 */
- (void)setBodyTextFontFamily:(NSString *)bodyTextFontFamily withSize:(CGFloat)size;

/** Set Buttons font family and size
 *
 * @param buttonsFontFamily The family name used to displayed the buttons.
 * @param size Font size.
 */
- (void)setButtonsTextFontFamily:(NSString *)buttonsFontFamily withSize:(CGFloat)size;

/** Add a Button with a title and a block to handle when the button is pressed.
 *
 * @param title The text displayed on the button.
 * @param action A block of code to be executed when the button is pressed.
 */
- (TSTButton *)addButton:(NSString *)title actionBlock:(TSTActionBlock)action;

/** Add a Button with a title, a block to handle validation, and a block to handle when the button is pressed and validation succeeds.
 *
 * @param title The text displayed on the button.
 * @param validationBlock A block of code that will allow you to validate fields or do any other logic you may want to do to determine if the alert should be dismissed or not. Inside of this block, return a BOOL indicating whether or not the action block should be called and the alert dismissed.
 * @param action A block of code to be executed when the button is pressed and validation passes.
 */
- (TSTButton *)addButton:(NSString *)title validationBlock:(TSTValidationBlock)validationBlock actionBlock:(TSTActionBlock)action;

/** Add a Button with a title, a target and a selector to handle when the button is pressed.
 *
 * @param title The text displayed on the button.
 * @param target Add target for particular event.
 * @param selector A method to be executed when the button is pressed.
 */
- (TSTButton *)addButton:(NSString *)title target:(id)target selector:(SEL)selector;

/** Show Success TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showSuccess:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showSuccess:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Error TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showError:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showError:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Notice TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showNotice:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showNotice:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Warning TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showWarning:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showWarning:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Info TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showInfo:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showInfo:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Edit TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showEdit:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showEdit:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Title TSTAlertView using a predefined type
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param style One of predefined TSTAlertView styles.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showTitle:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle style:(TSTAlertViewStyle)style closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showTitle:(NSString *)title subTitle:(NSString *)subTitle style:(TSTAlertViewStyle)style closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Shows a custom TSTAlertView without using a predefined type, allowing for a custom image and color to be specified.
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param image A UIImage object to be used as the icon for the alert view.
 * @param color A UIColor object to be used to tint the background of the icon circle and the buttons.
 * @param title The title text of the alert view.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showCustom:(UIViewController *)vc image:(UIImage *)image color:(UIColor *)color title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showCustom:(UIImage *)image color:(UIColor *)color title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Waiting TSTAlertView with UIActityIndicator.
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showWaiting:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showWaiting:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

/** Show Question TSTAlertView
 *
 * @param vc The view controller the alert view will be displayed in.
 * @param title The text displayed on the button.
 * @param subTitle The subtitle text of the alert view.
 * @param closeButtonTitle The text for the close button.
 * @param duration The amount of time the alert will remain on screen until it is automatically dismissed. If automatic dismissal is not desired, set to 0.
 */
- (void)showQuestion:(UIViewController *)vc title:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;
- (void)showQuestion:(NSString *)title subTitle:(NSString *)subTitle closeButtonTitle:(NSString *)closeButtonTitle duration:(NSTimeInterval)duration;

@end

@interface TSTAlertViewShowBuilder : NSObject

@property(weak, nonatomic, readonly) UIViewController *parameterViewController;
@property(copy, nonatomic, readonly) UIImage *parameterImage;
@property(copy, nonatomic, readonly) UIColor *parameterColor;
@property(copy, nonatomic, readonly) NSString *parameterTitle;
@property(copy, nonatomic, readonly) NSString *parameterSubTitle;
@property(copy, nonatomic, readonly) NSString *parameterCompleteText;
@property(copy, nonatomic, readonly) NSString *parameterCloseButtonTitle;
@property(assign, nonatomic, readonly) TSTAlertViewStyle parameterStyle;
@property(assign, nonatomic, readonly) NSTimeInterval parameterDuration;

#pragma mark - Setters
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^viewController)(UIViewController *viewController);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^image)(UIImage *image);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^color)(UIColor *color);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^title)(NSString *title);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^subTitle)(NSString *subTitle);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^completeText)(NSString *completeText);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^style)(TSTAlertViewStyle style);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^closeButtonTitle)(NSString *closeButtonTitle);
@property(copy, nonatomic, readonly) TSTAlertViewShowBuilder *(^duration)(NSTimeInterval duration);

- (void)showAlertView:(TSTAlertView *)alertView;
- (void)showAlertView:(TSTAlertView *)alertView onViewController:(UIViewController *)controller;
@property(copy, nonatomic, readonly) void (^show)(TSTAlertView *view, UIViewController *controller);
@end

@interface TSTALertViewTextFieldBuilder : NSObject

#pragma mark - Available later after adding
@property(weak, nonatomic, readonly) TSTTextView *textField;

#pragma mark - Setters
@property(copy, nonatomic, readonly) TSTALertViewTextFieldBuilder *(^title) (NSString *title);

@end

@interface TSTALertViewButtonBuilder : NSObject

#pragma mark - Available later after adding
@property(weak, nonatomic, readonly) TSTButton *button;

#pragma mark - Setters
@property(copy, nonatomic, readonly) TSTALertViewButtonBuilder *(^title) (NSString *title);
@property(copy, nonatomic, readonly) TSTALertViewButtonBuilder *(^target) (id target);
@property(copy, nonatomic, readonly) TSTALertViewButtonBuilder *(^selector) (SEL selector);
@property(copy, nonatomic, readonly) TSTALertViewButtonBuilder *(^actionBlock) (void(^actionBlock)(void));
@property(copy, nonatomic, readonly) TSTALertViewButtonBuilder *(^validationBlock) (BOOL(^validationBlock)(void));

@end

@interface TSTAlertViewBuilder : NSObject

#pragma mark - Parameters
@property (strong, nonatomic, readonly) TSTAlertView *alertView;

#pragma mark - Init
- (instancetype)init;
- (instancetype)initWithNewWindow;
- (instancetype)initWithNewWindowWidth:(CGFloat)width;

#pragma mark - Properties
@property(copy, nonatomic) TSTAlertViewBuilder *(^cornerRadius) (CGFloat cornerRadius);
@property(copy, nonatomic) TSTAlertViewBuilder *(^tintTopCircle) (BOOL tintTopCircle);
@property(copy, nonatomic) TSTAlertViewBuilder *(^useLargerIcon) (BOOL useLargerIcon);
@property(copy, nonatomic) TSTAlertViewBuilder *(^labelTitle) (UILabel *labelTitle);
@property(copy, nonatomic) TSTAlertViewBuilder *(^viewText) (UITextView *viewText);
@property(copy, nonatomic) TSTAlertViewBuilder *(^activityIndicatorView) (UIActivityIndicatorView *activityIndicatorView);
@property(copy, nonatomic) TSTAlertViewBuilder *(^shouldDismissOnTapOutside) (BOOL shouldDismissOnTapOutside);
@property(copy, nonatomic) TSTAlertViewBuilder *(^soundURL) (NSURL *soundURL);
@property(copy, nonatomic) TSTAlertViewBuilder *(^attributedFormatBlock) (TSTAttributedFormatBlock attributedFormatBlock);
@property(copy, nonatomic) TSTAlertViewBuilder *(^completeButtonFormatBlock) (CompleteButtonFormatBlock completeButtonFormatBlock);
@property(copy, nonatomic) TSTAlertViewBuilder *(^buttonFormatBlock) (ButtonFormatBlock buttonFormatBlock);
@property(copy, nonatomic) TSTAlertViewBuilder *(^forceHideBlock) (TSTForceHideBlock forceHideBlock);
@property(copy, nonatomic) TSTAlertViewBuilder *(^hideAnimationType) (TSTAlertViewHideAnimation hideAnimationType);
@property(copy, nonatomic) TSTAlertViewBuilder *(^showAnimationType) (TSTAlertViewShowAnimation showAnimationType);
@property(copy, nonatomic) TSTAlertViewBuilder *(^backgroundType) (TSTAlertViewBackground backgroundType);
@property(copy, nonatomic) TSTAlertViewBuilder *(^customViewColor) (UIColor *customViewColor);
@property(copy, nonatomic) TSTAlertViewBuilder *(^backgroundViewColor) (UIColor *backgroundViewColor);
@property(copy, nonatomic) TSTAlertViewBuilder *(^iconTintColor) (UIColor *iconTintColor);
@property(copy, nonatomic) TSTAlertViewBuilder *(^circleIconHeight) (CGFloat circleIconHeight);
@property(copy, nonatomic) TSTAlertViewBuilder *(^extensionBounds) (CGRect extensionBounds);
@property(copy, nonatomic) TSTAlertViewBuilder *(^statusBarHidden) (BOOL statusBarHidden);
@property(copy, nonatomic) TSTAlertViewBuilder *(^statusBarStyle) (UIStatusBarStyle statusBarStyle);

#pragma mark - Custom Setters
@property(copy, nonatomic) TSTAlertViewBuilder *(^alertIsDismissed) (TSTDismissBlock dismissBlock);
@property(copy, nonatomic) TSTAlertViewBuilder *(^removeTopCircle)(void);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addCustomView)(UIView *view);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addTextField)(NSString *title);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addCustomTextField)(UITextField *textField);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addSwitchViewWithLabelTitle)(NSString *title);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addTimerToButtonIndex)(NSInteger buttonIndex, BOOL reverse);
@property(copy, nonatomic) TSTAlertViewBuilder *(^setTitleFontFamily)(NSString *titleFontFamily, CGFloat size);
@property(copy, nonatomic) TSTAlertViewBuilder *(^setBodyTextFontFamily)(NSString *bodyTextFontFamily, CGFloat size);
@property(copy, nonatomic) TSTAlertViewBuilder *(^setButtonsTextFontFamily)(NSString *buttonsFontFamily, CGFloat size);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addButtonWithActionBlock)(NSString *title, TSTActionBlock action);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addButtonWithValidationBlock)(NSString *title, TSTValidationBlock validationBlock, TSTActionBlock action);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addButtonWithTarget)(NSString *title, id target, SEL selector);

#pragma mark - Builders
@property(copy, nonatomic) TSTAlertViewBuilder *(^addButtonWithBuilder)(TSTALertViewButtonBuilder *builder);
@property(copy, nonatomic) TSTAlertViewBuilder *(^addTextFieldWithBuilder)(TSTALertViewTextFieldBuilder *builder);

@end
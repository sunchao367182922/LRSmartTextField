//
//  LRTextField.h
//  LRTextField
//
//  Created by LR Studio on 7/26/15.
//  Copyright (c) 2015 LR Studio. All rights reserved.
//

#import <UIKit/UIKit.h>

#define VALIDATION_INDICATOR_YES @"YES"
#define VALIDATION_INDICATOR_NO  @"NO"

@class LRTextField;

typedef NS_ENUM(NSInteger, LRTextFieldStyle)
{
    LRTextFieldStyleEmail,          //Default placeholder: 'Email';   Default validation: email validation regular expression
    LRTextFieldStylePhone,          //Default placeholder: 'Phone';   Default format: '###-###-####'
    LRTextFieldStylePassword,       //Default placeholder: 'Password; Default: secure text entry
    LRTextFieldStyleNone,           //Default style
};

/**
 * Validation block to be applied to validate raw text synchronously or asynchronously.
 * @param text The raw text of the text field
 * @param textField
 * @return A dictionary with key of YES or NO and value of string to be displayed.
 */
typedef NSDictionary *(^ValidationBlock)(LRTextField *textField, NSString *text);

IB_DESIGNABLE
@interface LRTextField : UITextField

/**
 * Style of text: email, phone, password
 * Default is nil.
 */
@property (nonatomic, assign) LRTextFieldStyle style;

/**
 * Height of floating Label.
 * Default is 0.0f.
 */
@property (nonatomic, assign) IBInspectable CGFloat floatingLabelHeight;

/**
 * Mask of input text.
 * Default is nil.
 */
@property (nonatomic, copy) IBInspectable NSString *format;

/**
 * Text without mask.
 * Default is nil.
 */
@property (nonatomic, copy, readonly) NSString *rawText;

/**
 * Indicate whether the floating label animation is enabled.
 * Default is YES.
 */
@property (nonatomic) IBInspectable BOOL enableAnimation;

/**
 * Text color to be applied to floating placeholder text when editing.
 * Default is tint color.
 */
@property (nonatomic, strong) IBInspectable UIColor *placeholderActiveColor;

/**
 * Text color to be applied to floating placeholder text when not editing.
 * Default is 70% gray.
 */
@property (nonatomic, strong) IBInspectable UIColor *placeholderInactiveColor;

/**
 * Text to be displayed in the floating hint label.
 * Default is nil.
 */
@property (nonatomic, copy) IBInspectable NSString *hintText;

/**
 * Text color to be applied to the floating hint text.
 * Default is [UIColor grayColor].
 */
@property (nonatomic, strong) IBInspectable UIColor *hintTextColor;



- (instancetype) initWithFrame:(CGRect)frame labelHeight:(CGFloat)labelHeight;

/**
 * Init with style.
 *
 * @param frame The frame of text field
 * @param style The style of text field
 */
- (instancetype) initWithFrame:(CGRect)frame labelHeight:(CGFloat)labelHeight style:(LRTextFieldStyle)style;

/**
 * Set validation block.
 *
 * @param block The block to be applied to validate input text and return valid and invalid output.
 */
- (void) setValidationBlock:(ValidationBlock)block;

@end

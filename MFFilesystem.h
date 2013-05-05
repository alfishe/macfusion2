//
//  MFFilesystem.h
//  MacFusion2
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Cocoa/Cocoa.h>
#import "MFFSDelegateProtocol.h"

@class MFPlugin;

@interface MFFilesystem : NSObject {
	NSMutableDictionary* parameters;
	NSMutableDictionary* statusInfo;
	id <MFFSDelegateProtocol> delegate;
	NSMutableDictionary* secrets;
}


// Key action methods
- (void)mount;
- (void)unmount;

// shortcut methods
- (BOOL)isMounted;
- (BOOL)isWaiting;
- (BOOL)isUnmounted;
- (BOOL)isFailedToMount;
- (BOOL)isPersistent;

- (NSMutableDictionary*)parametersWithImpliedValues;
- (NSArray *)parameterList;
- (id)valueForParameterNamed:(NSString *)paramName;
- (NSMutableDictionary*)fillParametersWithImpliedValues:(NSDictionary *)params;
- (NSError *)error;
- (id <MFFSDelegateProtocol>)delegate;
- (void)updateSecrets;

@property(readwrite, strong) NSString *status;
@property(readonly, strong) NSString *uuid;
@property(weak, readonly) NSString *mountPath;
@property(weak, readonly) NSString *name;
@property(weak, readonly) NSMutableDictionary *parameters;
@property(weak, readonly) NSDictionary *statusInfo;
@property (readwrite, strong) NSMutableDictionary *secrets;
@property(weak, readonly) NSString *pluginID;
@property(weak, readonly) NSString *descriptionString;
@property(weak, readonly) NSString *iconPath;
@property(weak, readonly) NSString *filePath;
@property(weak, readonly) NSString *imagePath;

@end

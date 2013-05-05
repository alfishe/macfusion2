//
//  MFClient.h
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
#import "MFServerProtocol.h"
#import "MFClientDelegateProtocol.h"

@class MFClientFS, MFClientPlugin, MFClientRecent;

@interface MFClient : NSObject <MFClientProtocol> {
	NSMutableDictionary *filesystemsDictionary;
	NSMutableArray *__weak persistentFilesystems;
	NSMutableArray *__weak temporaryFilesystems;
	NSMutableDictionary *pluginsDictionary;
	NSMutableArray *__weak plugins;
	NSMutableArray *__weak recents;
	id <MFServerProtocol> server;
	id<MFClientDelegateProtocol> delegate;
	NSConnection *connection;
}

+ (MFClient *)sharedClient;

// Initialization
- (BOOL)setup;
- (void)fillInitialStatus;
- (BOOL)establishCommunication;

// Action methods
- (MFClientFS *)newFilesystemWithPlugin:(MFClientPlugin *)plugin;
- (MFClientFS *)quickMountFilesystemWithURL:(NSURL *)url error:(NSError **)error;
- (MFClientFS *)mountRecent:(MFClientRecent *)recent error:(NSError **)error;
- (void)deleteFilesystem:(MFClientFS *)fs;

// Accessors
- (MFClientFS *)filesystemWithUUID:(NSString *)uuid;
- (MFClientPlugin *)pluginWithID:(NSString *)id;

@property(strong) id delegate;

// All filesystems, including temporary ones
@property(weak, readonly) NSArray *filesystems;

// Only filesystems that are not temporary
@property(weak, readonly) NSArray *persistentFilesystems;
@property(weak, readonly) NSArray *temporaryFilesystems;
@property(weak, readonly) NSArray *mountedFilesystems;

// All plugins
@property (weak, readonly) NSArray *plugins;
@property(weak, readonly) NSArray *recents;

// UI Stuff
- (void)moveUUIDS:(NSArray *)uuid toRow:(NSUInteger)row;
- (NSString *)createMountIconForFilesystem:(MFClientFS *)fs atPath:(NSURL *)path;

@end

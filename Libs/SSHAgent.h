#import <Foundation/Foundation.h>

@interface SSHAgent : NSObject 
{
	int thePID;
	int s;

	NSString *socketPath;
	NSString *agentSocketPath;

	NSArray *keysOnAgent;

	/* Locks */
	NSLock *socketPathLock;
	NSLock *agentSocketPathLock;
	NSLock *keysOnAgentLock;
	NSLock *thePIDLock;
}

+ (id)currentAgent;

- (void)setSocketPath:(NSString *)path;

- (NSString *)socketPath;
- (NSString *)agentSocketPath;

- (BOOL)start;
- (BOOL)stop;

- (BOOL)isRunning;
- (int)PID;
- (NSArray *)keysOnAgent;

- (void)closeSockets;

- (void)handleAgentConnections;
- (void)inputFromClient:(id)object;
- (void)checkAgent;

- (NSArray *)currentKeysOnAgent;

@end

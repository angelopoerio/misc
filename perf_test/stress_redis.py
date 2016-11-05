import redis
r=redis.client.StrictRedis('127.0.0.1')

for i in range(10**6):
	r.set('key_{0}'.format(i),0)

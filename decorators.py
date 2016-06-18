'''
 Some decorators I wrote - Angelo Poerio <angelo.poerio@gmail.com>
'''

import time
import traceback
import requests
from functools import wraps

def retry(timeout=0, max_retries=10):
	'''
		Example usage:
			@retry(max_retries=1)
			def retry_me():
				0/0
	'''
	def wrap(fn):
		@wraps(fn)
		def wrapped(*args, **kwargs):
			try:
				fn(*args, **kwargs)
			except Exception as ex:
				time.sleep(timeout)
				if wrapped.done_retries > 0:
					wrapped.done_retries -= 1		
					wrapped(*args, **kwargs)
		wrapped.done_retries = max_retries
		return wrapped
	return wrap

def crash_report(endpoint):
	'''
		Example usage:
		@crash_report('http://report.me/crash_report')
		def crashing_method():
			return 1 / 0
	'''
	def wrap(fn):
		@wraps(fn)
		def wrapped(*args, **kwargs):
			try:
				fn(*args, **kwargs)
			except Exception as ex:
				trb = {'traceback': traceback.format_exc()}
				requests.post(endpoint, json=trb)
		return wrapped
	return wrap



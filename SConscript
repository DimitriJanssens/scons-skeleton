Import('env')

SUBDIRS = [
	'applications',
  'documentation',
	'framework',
	'third-party',
]

env.SConscript(dirs=SUBDIRS, name='SConscript', exports = 'env')

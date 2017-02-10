Import('env')

# first check our toolchains ... they might change some env flags like compiler, ...
SUBDIRS = [
	'toolchains',
]

env.SConscript(dirs=SUBDIRS, name='SConscript', exports = 'env')

# now check our sources
SUBDIRS = [
  'energyville',
  'framework',
]

env.SConscript(dirs=SUBDIRS, name='SConscript', exports = 'env')

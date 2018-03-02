project('libcallistashared', 'cpp', default_options : ['cpp_std=c++11'])

# macOS and iOS UIs can only really be written with Swift, so we have to play ball
# with Apple's meme language.
if host_machine.system() == 'darwin'
	add_languages('swift')
	source_glob = ['src/', '-name', '*.cpp', '-o', '-name', '*.swift']
else
	source_glob = ['src/', '-name', '*.cpp']
endif

# Because of the globbing, we have to re-run meson every build.
find_result = run_command('find', source_glob)
sources = find_result.stdout().strip().split('\n')

inc = include_directories('include')


thread_dep = dependency('threads')

gtk_dep=[]
#gtkmm_dep=[]

if host_machine.system() == 'linux'
	gtk_dep = dependency('gtk+-3.0')
	#gtkmm_dep = dependency('gtkmm-3.0')
endif


dependency_list = [gtk_dep, thread_dep]


callista_lib = library('callistashared', sources, include_directories: inc, dependencies: dependency_list, cpp_args : '-D_CS__SHARED')

callista_dep = declare_dependency(
  include_directories: inc,
  dependencies: dependency_list,
  link_with: callista_lib
)
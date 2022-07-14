api_version = '0.1'

smooth_progress_sources = [
  'smooth-progress.c',
]

smooth_progress_headers = [
  'smooth-progress.h',
]

version_split = meson.project_version().split('.')
MAJOR_VERSION = version_split[0]
MINOR_VERSION = version_split[1]
MICRO_VERSION = version_split[2]

version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', MAJOR_VERSION)
version_conf.set('MINOR_VERSION', MINOR_VERSION)
version_conf.set('MICRO_VERSION', MICRO_VERSION)

configure_file(
  input: 'smooth-progress-version.h.in',
  output: 'smooth-progress-version.h',
  configuration: version_conf,
  install: true,
  install_dir: join_paths(get_option('includedir'), 'smooth-progress')
)

smooth_progress_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
]

smooth_progress_lib = shared_library('smooth-progress-' + api_version,
  smooth_progress_sources,
  dependencies: smooth_progress_deps,
  install: true,
)

install_headers(smooth_progress_headers, subdir: 'smooth-progress')

pkg = import('pkgconfig')

pkg.generate(
  description: 'A shared library for ...',
    libraries: smooth_progress_lib,
         name: 'smooth-progress',
     filebase: 'smooth-progress-' + api_version,
      version: meson.project_version(),
      subdirs: 'smooth-progress',
     requires: 'glib-2.0',
  install_dir: join_paths(get_option('libdir'), 'pkgconfig')
)

// defaults.h.in
/*

Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2002,
              2003, 2004, 2005, 2006, 2007, 2009 John W. Eaton

This file is part of Octave.

Octave is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

Octave is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<http://www.gnu.org/licenses/>.

*/

#if !defined (octave_defaults_h)
#define octave_defaults_h 1

#include <string>

#include "pathsearch.h"

#ifndef OCTAVE_CANONICAL_HOST_TYPE
#define OCTAVE_CANONICAL_HOST_TYPE "x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_DEFAULT_PAGER
#define OCTAVE_DEFAULT_PAGER "less"
#endif

#ifndef OCTAVE_ARCHLIBDIR
#define OCTAVE_ARCHLIBDIR "/usr/libexec/octave/3.2.4/exec/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_BINDIR
#define OCTAVE_BINDIR "/usr/bin"
#endif

#ifndef OCTAVE_DATADIR
#define OCTAVE_DATADIR "/usr/share"
#endif

#ifndef OCTAVE_DATAROOTDIR
#define OCTAVE_DATAROOTDIR "/usr/share"
#endif

#ifndef OCTAVE_DOC_CACHE_FILE
#define OCTAVE_DOC_CACHE_FILE "/usr/share/octave/3.2.4/etc/doc-cache"
#endif

#ifndef OCTAVE_EXEC_PREFIX
#define OCTAVE_EXEC_PREFIX "/usr"
#endif

#ifndef OCTAVE_FCNFILEDIR
#define OCTAVE_FCNFILEDIR "/usr/share/octave/3.2.4/m"
#endif

#ifndef OCTAVE_IMAGEDIR
#define OCTAVE_IMAGEDIR "/usr/share/octave/3.2.4/imagelib"
#endif

#ifndef OCTAVE_INCLUDEDIR
#define OCTAVE_INCLUDEDIR "/usr/include"
#endif

#ifndef OCTAVE_INFODIR
#define OCTAVE_INFODIR "/usr/share/info"
#endif

#ifndef OCTAVE_INFOFILE
#define OCTAVE_INFOFILE "/usr/share/info/octave.info"
#endif

#ifndef OCTAVE_LIBDIR
#define OCTAVE_LIBDIR "/usr/lib64"
#endif

#ifndef OCTAVE_LIBEXECDIR
#define OCTAVE_LIBEXECDIR "/usr/libexec"
#endif

#ifndef OCTAVE_LIBEXECDIR
#define OCTAVE_LIBEXECDIR "/usr/libexec"
#endif

#ifndef OCTAVE_LOCALAPIFCNFILEDIR
#define OCTAVE_LOCALAPIFCNFILEDIR "/usr/share/octave/site/api-v37/m"
#endif

#ifndef OCTAVE_LOCALAPIOCTFILEDIR
#define OCTAVE_LOCALAPIOCTFILEDIR "/usr/libexec/octave/site/oct/api-v37/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_LOCALARCHLIBDIR
#define OCTAVE_LOCALARCHLIBDIR "/usr/libexec/octave/site/exec/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_LOCALFCNFILEDIR
#define OCTAVE_LOCALFCNFILEDIR "/usr/share/octave/site/m"
#endif

#ifndef OCTAVE_LOCALOCTFILEDIR
#define OCTAVE_LOCALOCTFILEDIR "/usr/libexec/octave/site/oct/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_LOCALSTARTUPFILEDIR
#define OCTAVE_LOCALSTARTUPFILEDIR "/usr/share/octave/site/m/startup"
#endif

#ifndef OCTAVE_LOCALAPIARCHLIBDIR
#define OCTAVE_LOCALAPIARCHLIBDIR "/usr/libexec/octave/api-v37/site/exec/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_LOCALVERARCHLIBDIR
#define OCTAVE_LOCALVERARCHLIBDIR "/usr/libexec/octave/3.2.4/site/exec/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_LOCALVERFCNFILEDIR
#define OCTAVE_LOCALVERFCNFILEDIR "/usr/share/octave/3.2.4/site/m"
#endif

#ifndef OCTAVE_LOCALVEROCTFILEDIR
#define OCTAVE_LOCALVEROCTFILEDIR "/usr/libexec/octave/3.2.4/site/oct/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_MAN1DIR
#define OCTAVE_MAN1DIR "/usr/share/man/man1"
#endif

#ifndef OCTAVE_MAN1EXT
#define OCTAVE_MAN1EXT ".1"
#endif

#ifndef OCTAVE_MANDIR
#define OCTAVE_MANDIR "/usr/share/man"
#endif

#ifndef OCTAVE_OCTFILEDIR
#define OCTAVE_OCTFILEDIR "/usr/libexec/octave/3.2.4/oct/x86_64-redhat-linux-gnu"
#endif

#ifndef OCTAVE_OCTETCDIR
#define OCTAVE_OCTETCDIR "/usr/share/octave/3.2.4/etc"
#endif

#ifndef OCTAVE_OCTINCLUDEDIR
#define OCTAVE_OCTINCLUDEDIR "/usr/include/octave-3.2.4"
#endif

#ifndef OCTAVE_OCTLIBDIR
#define OCTAVE_OCTLIBDIR "/usr/lib64/octave-3.2.4"
#endif

#ifndef OCTAVE_PREFIX
#define OCTAVE_PREFIX "/usr"
#endif

#ifndef OCTAVE_STARTUPFILEDIR
#define OCTAVE_STARTUPFILEDIR "/usr/share/octave/3.2.4/m/startup"
#endif

#ifndef OCTAVE_RELEASE
#define OCTAVE_RELEASE ""
#endif

extern std::string Voctave_home;

extern std::string Vbin_dir;
extern std::string Vinfo_dir;
extern std::string Vdata_dir;
extern std::string Vlibexec_dir;
extern std::string Varch_lib_dir;
extern std::string Vlocal_arch_lib_dir;
extern std::string Vlocal_ver_arch_lib_dir;

extern std::string Vlocal_ver_oct_file_dir;
extern std::string Vlocal_api_oct_file_dir;
extern std::string Vlocal_oct_file_dir;

extern std::string Vlocal_ver_fcn_file_dir;
extern std::string Vlocal_api_fcn_file_dir;
extern std::string Vlocal_fcn_file_dir;

extern std::string Voct_file_dir;
extern std::string Vfcn_file_dir;

extern std::string Vimage_dir;

// Name of the editor to be invoked by the edit_history command.
extern std::string VEDITOR;

extern std::string Vlocal_site_defaults_file;
extern std::string Vsite_defaults_file;

// Name of the FFTW wisdom program.
extern OCTINTERP_API std::string Vfftw_wisdom_program;

extern std::string subst_octave_home (const std::string&);

extern void install_defaults (void);

extern void set_exec_path (const std::string& path = std::string ());
extern void set_image_path (const std::string& path = std::string ());

#endif

/*
;;; Local Variables: ***
;;; mode: C++ ***
;;; page-delimiter: "^/\\*" ***
;;; End: ***
*/

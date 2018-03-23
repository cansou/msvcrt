####
# makefile.inc - Included makefile for VCRT build process
#
#   Copyright (c) Microsoft Corporation. All rights reserved.
#
#
###############################################################################

PREOBJDIR = $(CPUDIR)\$(BLD_MODEL)_lib

# These are the prebuilt objects which are static link components in the
# MSVCRXX[D].DLL implib

DLL_STAT_PREBLD = \
!if "$(TARGET_CPU)"=="AMD64"
        $(OBJDIR)\gshandlereh.obj \
!elseif "$(TARGET_CPU)"=="IA64"
        $(OBJDIR)\gshandlereh.obj \
!elseif "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\ehprolg2.obj \
        $(OBJDIR)\ehprolg3.obj \
        $(OBJDIR)\ehprolg3a.obj \
        $(OBJDIR)\ehprolog.obj \
        $(OBJDIR)\cpu_disp.obj \
        $(OBJDIR)\ftol2.obj \
!endif
        $(OBJDIR)\ehvccctr.obj \
        $(OBJDIR)\ehvcccvb.obj \
        $(OBJDIR)\ehvecctr.obj \
        $(OBJDIR)\ehveccvb.obj \
!if "$(BLD_SYSCRT)" != "1"
        $(OBJDIR)\tncleanup.obj \
!endif
        $(OBJDIR)\ehvecdtr.obj

# Here is the target for building LIBC{,D} / LIBCMT{,D} / MSVCRT{,D}.LIB

all: \
        $(OBJDIR)\convert.lib  \
        $(OBJDIR)\direct.lib   \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\dllstuff.lib \
!endif
        $(OBJDIR)\dos.lib      \
        $(OBJDIR)\eh.lib       \
        $(OBJDIR)\exec.lib     \
        $(OBJDIR)\heap.lib     \
!if "$(TARGET_CPU)"!="AMD64"
        $(OBJDIR)\helper.lib   \
!endif
!if "$(BLD_DLL)"!="1"
        $(OBJDIR)\linkopts.lib \
        $(OBJDIR)\plinkopts.lib \
!endif
        $(OBJDIR)\lowio.lib    \
        $(OBJDIR)\mbstring.lib \
        $(OBJDIR)\misc.lib     \
!if "$(RTC)"=="YES"
        $(OBJDIR)\rtc.lib      \
!endif
        $(OBJDIR)\startup.lib  \
        $(OBJDIR)\stdio.lib    \
        $(OBJDIR)\string.lib   \
        $(OBJDIR)\time.lib     \
        $(OBJDIR)\conv.lib     \
        $(OBJDIR)\tran.lib     \
!if "$(BLD_BSKU)"=="1"
        $(OBJDIR)\bsku.obj     \
!endif
        $(OBJDIR)\matherr.obj  \
!if "$(BLD_DLL)"=="1"
        $(DLL_STAT_PREBLD)
!endif
    

STDCPP_SRC = stdcpp

_stdcpp_ : \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\newaop_s.obj  \
!endif
!if "$(BLD_BSKU)"=="1"
        $(OBJDIR)\bsku.obj     \
!endif
        $(OBJDIR)\$(STDCPP_SRC).lib

CONVERT_OBJECTS = \
        $(OBJDIR)\_fptostr.obj 		\
        $(OBJDIR)\atox.obj     		\
        $(OBJDIR)\swab.obj     		\
        $(OBJDIR)\wchtodig.obj 		\
        $(OBJDIR)\wtox.obj     		\
        $(OBJDIR)\xtoa.obj     		\
        $(OBJDIR)\xtoas.obj    		\
        $(OBJDIR)\xtow.obj     		\
        $(OBJDIR)\xtows.obj    		\
        $(CPP_OBJDIR)\_ctype.obj	\
        $(CPP_OBJDIR)\_mbslen.obj	\
        $(CPP_OBJDIR)\_mbslen_s.obj \
        $(CPP_OBJDIR)\_wctype.obj  	\
        $(CPP_OBJDIR)\atodbl.obj   	\
        $(CPP_OBJDIR)\atof.obj     	\
        $(CPP_OBJDIR)\fcvt.obj     	\
        $(CPP_OBJDIR)\gcvt.obj     	\
        $(CPP_OBJDIR)\iswctype.obj 	\
        $(CPP_OBJDIR)\isctype.obj  	\
        $(CPP_OBJDIR)\mblen.obj    	\
        $(CPP_OBJDIR)\mbstowcs.obj 	\
        $(CPP_OBJDIR)\mbtowc.obj   	\
        $(CPP_OBJDIR)\mbrtowc.obj  	\
        $(CPP_OBJDIR)\strtod.obj   	\
        $(CPP_OBJDIR)\strtol.obj   	\
        $(CPP_OBJDIR)\strtoq.obj   	\
        $(CPP_OBJDIR)\tolower.obj  	\
        $(CPP_OBJDIR)\toupper.obj  	\
        $(CPP_OBJDIR)\towlower.obj 	\
        $(CPP_OBJDIR)\towupper.obj 	\
        $(CPP_OBJDIR)\wcrtomb.obj  	\
        $(CPP_OBJDIR)\wcstod.obj   	\
        $(CPP_OBJDIR)\wcstol.obj   	\
        $(CPP_OBJDIR)\wcstoq.obj   	\
        $(CPP_OBJDIR)\wcstombs.obj 	\
        $(CPP_OBJDIR)\wctomb.obj	\
        $(CPP_OBJDIR)\wtof.obj

DIRECT_OBJECTS = \
        $(OBJDIR)\drivemap.obj \
        $(OBJDIR)\drivfree.obj \
        $(OBJDIR)\findfile.obj \
        $(OBJDIR)\findf64.obj  \
        $(OBJDIR)\findfi32.obj \
        $(OBJDIR)\findfi64.obj \
        $(OBJDIR)\seterrm.obj  \
        $(OBJDIR)\slbeep.obj   \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\enable.obj   \
!endif
        $(OBJDIR)\wfindfil.obj \
        $(OBJDIR)\wfndf64.obj  \
        $(OBJDIR)\wfndfi32.obj \
        $(OBJDIR)\wfndfi64.obj

DLLSTUFF_OBJECTS = \
        $(OBJDIR)\atonexit.obj \
        $(OBJDIR)\crtlib.obj   \
        $(OBJDIR)\crtexe.obj   \
        $(OBJDIR)\crtmanifest.obj   \
        $(OBJDIR)\crtmanifestrtm.obj   \
        $(OBJDIR)\crtmanifestcur.obj   \
        $(OBJDIR)\crtexew.obj  \
        $(OBJDIR)\crtdll.obj   \
        $(OBJDIR)\cinitexe.obj \
        $(OBJDIR)\dllargv.obj  \
        $(OBJDIR)\dll_argv.obj \
        $(OBJDIR)\merr.obj     \
        $(OBJDIR)\natstart.obj \
        $(OBJDIR)\oldexcpt.obj \
        $(OBJDIR)\ti_inst.obj  \
        $(OBJDIR)\unhandld.obj \
        $(OBJDIR)\wcrtexe.obj  \
        $(OBJDIR)\wcrtexew.obj \
        $(OBJDIR)\wdllargv.obj \
        $(OBJDIR)\wdll_av.obj  \
        $(OBJDIR)\wildcard.obj \
        $(OBJDIR)\xtxtmode.obj \
        $(OBJDIR)\xthdloc.obj \
        $(OBJDIR)\xncommod.obj \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\dllsupp.obj  \
        $(OBJDIR)\adjustfd.obj \
!endif
!if "$(TARGET_CPU)"=="AMD64"
        $(OBJDIR)\dllsupp.obj  \
!endif
!if "$(TARGET_CPU)"=="IA64"
        $(OBJDIR)\dllsupp.obj  \
!endif

DOS_OBJECTS = \
        $(OBJDIR)\access.obj   \
        $(OBJDIR)\chmod.obj    \
        $(OBJDIR)\chdir.obj    \
        $(OBJDIR)\dosmap.obj   \
        $(OBJDIR)\drive.obj    \
        $(OBJDIR)\fullpath.obj \
        $(OBJDIR)\getcwd.obj   \
        $(OBJDIR)\getpid.obj   \
        $(OBJDIR)\mkdir.obj    \
        $(OBJDIR)\mterrno.obj  \
        $(OBJDIR)\rename.obj   \
        $(OBJDIR)\rmdir.obj    \
        $(OBJDIR)\stat.obj     \
        $(OBJDIR)\stat64.obj   \
        $(OBJDIR)\stati32.obj  \
        $(OBJDIR)\stati64.obj  \
        $(OBJDIR)\unlink.obj   \
        $(OBJDIR)\waccess.obj  \
        $(OBJDIR)\wchdir.obj   \
        $(OBJDIR)\wchmod.obj   \
        $(OBJDIR)\wfullpat.obj \
        $(OBJDIR)\wgetcwd.obj  \
        $(OBJDIR)\wmkdir.obj   \
        $(OBJDIR)\wrename.obj  \
        $(OBJDIR)\wrmdir.obj   \
        $(OBJDIR)\wstat.obj    \
        $(OBJDIR)\wstat64.obj  \
        $(OBJDIR)\wstati32.obj \
        $(OBJDIR)\wstati64.obj \
        $(OBJDIR)\wunlink.obj

EXEC_OBJECTS = \
        $(OBJDIR)\cenvarg.obj  \
        $(OBJDIR)\dospawn.obj  \
        $(OBJDIR)\execl.obj    \
        $(OBJDIR)\execle.obj   \
        $(OBJDIR)\execlp.obj   \
        $(OBJDIR)\execlpe.obj  \
        $(OBJDIR)\execv.obj    \
        $(OBJDIR)\execve.obj   \
        $(OBJDIR)\execvp.obj   \
        $(OBJDIR)\execvpe.obj  \
        $(OBJDIR)\getproc.obj  \
        $(OBJDIR)\loaddll.obj  \
        $(OBJDIR)\spawnl.obj   \
        $(OBJDIR)\spawnle.obj  \
        $(OBJDIR)\spawnlp.obj  \
        $(OBJDIR)\spawnlpe.obj \
        $(OBJDIR)\spawnv.obj   \
        $(OBJDIR)\spawnve.obj  \
        $(OBJDIR)\spawnvp.obj  \
        $(OBJDIR)\spawnvpe.obj \
        $(OBJDIR)\system.obj   \
        $(OBJDIR)\wait.obj     \
        $(OBJDIR)\wcenvarg.obj \
        $(OBJDIR)\wdospawn.obj \
        $(OBJDIR)\wexecl.obj   \
        $(OBJDIR)\wexecle.obj  \
        $(OBJDIR)\wexeclp.obj  \
        $(OBJDIR)\wexeclpe.obj \
        $(OBJDIR)\wexecv.obj   \
        $(OBJDIR)\wexecve.obj  \
        $(OBJDIR)\wexecvp.obj  \
        $(OBJDIR)\wexecvpe.obj \
        $(OBJDIR)\wspawnl.obj  \
        $(OBJDIR)\wspawnle.obj \
        $(OBJDIR)\wspawnlp.obj \
        $(OBJDIR)\wspwnlpe.obj \
        $(OBJDIR)\wspawnv.obj  \
        $(OBJDIR)\wspawnve.obj \
        $(OBJDIR)\wspawnvp.obj \
        $(OBJDIR)\wspwnvpe.obj \
        $(OBJDIR)\wsystem.obj

HEAP_OBJECTS = \
        $(OBJDIR)\align.obj    \
        $(OBJDIR)\resetstk.obj  \
        $(OBJDIR)\calloc.obj   \
        $(OBJDIR)\calloc_impl.obj   \
        $(OBJDIR)\crtheap.obj   \
!IF "$(WINHEAP)" == "YES"
        $(OBJDIR)\expand.obj   \
!ELSE
        $(OBJDIR)\findaddr.obj \
!ENDIF
        $(OBJDIR)\free.obj     \
        $(OBJDIR)\freea.obj    \
        $(OBJDIR)\heapadd.obj  \
        $(OBJDIR)\heapchk.obj  \
!IF "$(WINHEAP)" == "NO"
        $(OBJDIR)\heapgrow.obj \
!ENDIF
        $(OBJDIR)\heapinit.obj \
        $(OBJDIR)\heapmin.obj  \
!IF "$(WINHEAP)" == "NO"
        $(OBJDIR)\heapprm.obj  \
!ENDIF
!IF "$(WINHEAP)" == "NO"
        $(OBJDIR)\heapsrch.obj \
!ENDIF
        $(OBJDIR)\hpabort.obj  \
        $(OBJDIR)\heapused.obj \
        $(OBJDIR)\heapwalk.obj \
        $(OBJDIR)\malloc.obj   \
        $(OBJDIR)\msize.obj    \
        $(OBJDIR)\realloc.obj  \
        $(OBJDIR)\recalloc.obj  \
!IF "$(WINHEAP)" == "YES"
        $(OBJDIR)\sbheap.obj   \
!ENDIF
        $(OBJDIR)\handler.obj  \
        $(OBJDIR)\setnewh.obj  \
        $(OBJDIR)\new_mode.obj \
        $(OBJDIR)\nothrow0.obj \
        $(OBJDIR)\delete.obj   \
        $(OBJDIR)\delete2.obj  \
        $(OBJDIR)\_newmode.obj \
        $(OBJDIR)\new.obj      \
!if "$(BLD_SYSCRT)" != "1"
        $(OBJDIR)\nomemoryh.obj \
!endif
        $(OBJDIR)\new2.obj     \
        $(OBJDIR)\delaopnt.obj \
        $(OBJDIR)\delopnt.obj  \
        $(OBJDIR)\newaopnt.obj \
        $(OBJDIR)\newopnt.obj

HELPER_OBJECTS = \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\lldiv.obj    \
        $(OBJDIR)\lldvrm.obj   \
        $(OBJDIR)\llmul.obj    \
        $(OBJDIR)\llrem.obj    \
        $(OBJDIR)\llshl.obj    \
        $(OBJDIR)\llshr.obj    \
        $(OBJDIR)\ulldiv.obj   \
        $(OBJDIR)\ulldvrm.obj  \
        $(OBJDIR)\ullrem.obj   \
        $(OBJDIR)\ullshr.obj   \
!endif
!if "$(TARGET_CPU)"=="IA64"
        $(OBJDIR)\divhelp.obj
!endif

LINKOPTS_OBJECTS = \
        $(OBJDIR)\binmode.obj  \
        $(OBJDIR)\commode.obj  \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\fp10.obj     \
!endif
!if "$(TARGET_CPU)"=="IA64"
        $(OBJDIR)\fp10.obj     \
!endif
        $(OBJDIR)\invalidcontinue.obj \
        $(OBJDIR)\loosefpmath.obj \
        $(OBJDIR)\newmode.obj  \
        $(OBJDIR)\noarg.obj    \
        $(OBJDIR)\nochkclr.obj \
        $(OBJDIR)\noenv.obj    \
        $(OBJDIR)\nothrownew.obj \
        $(OBJDIR)\setargv.obj  \
        $(OBJDIR)\smalheap.obj \
        $(OBJDIR)\threadlocale.obj \
        $(OBJDIR)\thrownew.obj \
        $(OBJDIR)\wsetargv.obj \

LOWIO_OBJECTS = \
        $(OBJDIR)\chsize.obj   \
        $(OBJDIR)\close.obj    \
        $(OBJDIR)\commit.obj   \
        $(OBJDIR)\creat.obj    \
        $(OBJDIR)\dup.obj      \
        $(OBJDIR)\dup2.obj     \
        $(OBJDIR)\eof.obj      \
        $(OBJDIR)\flength.obj  \
        $(OBJDIR)\fleni64.obj  \
        $(OBJDIR)\fstat.obj    \
        $(OBJDIR)\fstat64.obj  \
        $(OBJDIR)\fstati32.obj \
        $(OBJDIR)\fstati64.obj \
        $(OBJDIR)\initcon.obj  \
        $(OBJDIR)\ioinit.obj   \
        $(OBJDIR)\isatty.obj   \
        $(OBJDIR)\locking.obj  \
        $(OBJDIR)\lseek.obj    \
        $(OBJDIR)\lseeki64.obj \
        $(OBJDIR)\mktemp.obj   \
        $(OBJDIR)\open.obj     \
        $(OBJDIR)\openo.obj    \
        $(OBJDIR)\osfinfo.obj  \
        $(OBJDIR)\pipe.obj     \
        $(OBJDIR)\read.obj     \
        $(OBJDIR)\setmode.obj  \
        $(OBJDIR)\tell.obj     \
        $(OBJDIR)\telli64.obj  \
        $(OBJDIR)\txtmode.obj  \
        $(OBJDIR)\write.obj    \
        $(OBJDIR)\cgets.obj    \
        $(OBJDIR)\cgetws.obj   \
        $(OBJDIR)\cputs.obj    \
        $(OBJDIR)\getch.obj    \
        $(OBJDIR)\getwch.obj   \
        $(OBJDIR)\putch.obj    \
        $(OBJDIR)\putwch.obj   \
        $(OBJDIR)\wcreat.obj   \
        $(OBJDIR)\wmktemp.obj  \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\inp.obj      \
        $(OBJDIR)\outp.obj     \
!endif
        $(OBJDIR)\wopen.obj

MBSTRING_OBJECTS = \
        $(OBJDIR)\mbclen.obj   \
        $(OBJDIR)\mbsinc.obj   \
        $(OBJDIR)\mbsninc.obj  \
        $(OBJDIR)\mbtohira.obj \
        $(OBJDIR)\mbtokata.obj \
        $(CPP_OBJDIR)\ismbalnm.obj \
        $(CPP_OBJDIR)\ismbalph.obj \
        $(CPP_OBJDIR)\ismbbyte.obj \
        $(CPP_OBJDIR)\ismbdgt.obj  \
        $(CPP_OBJDIR)\ismbgrph.obj \
        $(CPP_OBJDIR)\ismbknj.obj  \
        $(CPP_OBJDIR)\ismblgl.obj  \
        $(CPP_OBJDIR)\ismblwr.obj  \
        $(CPP_OBJDIR)\ismbprn.obj  \
        $(CPP_OBJDIR)\ismbpunc.obj \
        $(CPP_OBJDIR)\ismbsle.obj  \
        $(CPP_OBJDIR)\ismbspc.obj  \
        $(CPP_OBJDIR)\ismbstr.obj  \
        $(CPP_OBJDIR)\ismbupr.obj  \
        $(CPP_OBJDIR)\mbbtype.obj  \
        $(CPP_OBJDIR)\mbccpy.obj   \
        $(CPP_OBJDIR)\mbccpy_s.obj \
        $(CPP_OBJDIR)\mbccpy_s_l.obj \
        $(CPP_OBJDIR)\mbscat_s_l.obj \
        $(CPP_OBJDIR)\mbscpy_s_l.obj \
        $(CPP_OBJDIR)\mbsnbcat_s_l.obj \
        $(CPP_OBJDIR)\mbsnbcpy_s_l.obj \
        $(CPP_OBJDIR)\mbsnbset_s_l.obj \
        $(CPP_OBJDIR)\mbsncat_s_l.obj \
        $(CPP_OBJDIR)\mbsncpy_s_l.obj \
        $(CPP_OBJDIR)\mbsnset_s_l.obj \
        $(CPP_OBJDIR)\mbsset_s_l.obj \
        $(CPP_OBJDIR)\mbclevel.obj \
        $(CPP_OBJDIR)\mbctype.obj  \
        $(CPP_OBJDIR)\mbsbtype.obj \
        $(CPP_OBJDIR)\mbscat_s.obj \
        $(CPP_OBJDIR)\mbschr.obj   \
        $(CPP_OBJDIR)\mbscmp.obj   \
        $(CPP_OBJDIR)\mbscpy_s.obj \
        $(CPP_OBJDIR)\mbscoll.obj  \
        $(CPP_OBJDIR)\mbscspn.obj  \
        $(CPP_OBJDIR)\mbsdec.obj   \
        $(CPP_OBJDIR)\mbsicmp.obj  \
        $(CPP_OBJDIR)\mbsicoll.obj \
        $(CPP_OBJDIR)\mbslen.obj   \
        $(CPP_OBJDIR)\mbslen_s.obj \
        $(CPP_OBJDIR)\mbslwr.obj   \
        $(CPP_OBJDIR)\mbsnbcat.obj \
        $(CPP_OBJDIR)\mbsnbcat_s.obj \
        $(CPP_OBJDIR)\mbsnbcmp.obj \
        $(CPP_OBJDIR)\mbsnbcnt.obj \
        $(CPP_OBJDIR)\mbsnbcol.obj \
        $(CPP_OBJDIR)\mbsnbcpy.obj \
        $(CPP_OBJDIR)\mbsnbcpy_s.obj \
        $(CPP_OBJDIR)\mbsnbicm.obj \
        $(CPP_OBJDIR)\mbsnbico.obj \
        $(CPP_OBJDIR)\mbsnbset.obj \
        $(CPP_OBJDIR)\mbsnbset_s.obj \
        $(CPP_OBJDIR)\mbsncat.obj  \
        $(CPP_OBJDIR)\mbsncat_s.obj  \
        $(CPP_OBJDIR)\mbsnccnt.obj \
        $(CPP_OBJDIR)\mbsncmp.obj  \
        $(CPP_OBJDIR)\mbsncoll.obj \
        $(CPP_OBJDIR)\mbsncpy.obj  \
        $(CPP_OBJDIR)\mbsncpy_s.obj \
        $(CPP_OBJDIR)\mbsnextc.obj \
        $(CPP_OBJDIR)\mbsnicmp.obj \
        $(CPP_OBJDIR)\mbsnicol.obj \
        $(CPP_OBJDIR)\mbsnset.obj  \
        $(CPP_OBJDIR)\mbsnset_s.obj  \
        $(CPP_OBJDIR)\mbspbrk.obj  \
        $(CPP_OBJDIR)\mbsrchr.obj  \
        $(CPP_OBJDIR)\mbsrev.obj   \
        $(CPP_OBJDIR)\mbsset.obj   \
        $(CPP_OBJDIR)\mbsset_s.obj \
        $(CPP_OBJDIR)\mbsspn.obj   \
        $(CPP_OBJDIR)\mbsspnp.obj  \
        $(CPP_OBJDIR)\mbsstr.obj   \
        $(CPP_OBJDIR)\mbstok.obj   \
        $(CPP_OBJDIR)\mbstok_s.obj \
        $(CPP_OBJDIR)\mbsupr.obj   \
        $(CPP_OBJDIR)\mbtolwr.obj  \
        $(CPP_OBJDIR)\mbtoupr.obj  \
        $(CPP_OBJDIR)\tojisjms.obj \
        $(CPP_OBJDIR)\tombbmbc.obj

MISC_OBJECTS = \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\chandler4.obj\
        $(OBJDIR)\chandler4gs.obj\
        $(OBJDIR)\chkesp.obj   \
        $(OBJDIR)\eh3valid.obj \
        $(OBJDIR)\exsup.obj    \
        $(OBJDIR)\exsup2.obj   \
        $(OBJDIR)\exsup3.obj   \
        $(OBJDIR)\exsup4.obj   \
        $(OBJDIR)\loadcfg.obj  \
        $(OBJDIR)\longjmp.obj  \
        $(OBJDIR)\secchk.obj   \
        $(OBJDIR)\sehprolg.obj \
        $(OBJDIR)\sehprolg4.obj\
        $(OBJDIR)\sehprolg4gs.obj\
        $(OBJDIR)\sehsupp.obj  \
        $(OBJDIR)\calldtor.obj \
        $(OBJDIR)\setjmp.obj   \
        $(OBJDIR)\setjmp3.obj  \
        $(OBJDIR)\setjmpex.obj \
!endif
!if "$(TARGET_CPU)"=="AMD64"
        $(OBJDIR)\amdsecgs.obj \
        $(OBJDIR)\chandler.obj \
        $(OBJDIR)\gshandler.obj \
        $(OBJDIR)\gshandlerseh.obj \
        $(OBJDIR)\jmpuwind.obj \
        $(OBJDIR)\longjmp.obj  \
        $(OBJDIR)\rtcmd.obj    \
        $(OBJDIR)\setjmp.obj   \
        $(OBJDIR)\setjmpex.obj \
!endif
!if "$(TARGET_CPU)"=="IA64"
        $(OBJDIR)\chandler.obj \
        $(OBJDIR)\cinitone.obj \
        $(OBJDIR)\gshandler.obj \
        $(OBJDIR)\gshandlerseh.obj \
        $(OBJDIR)\jmpuwind.obj \
        $(OBJDIR)\longjmp.obj  \
        $(OBJDIR)\miscs.obj    \
        $(OBJDIR)\rtcmd.obj    \
        $(OBJDIR)\secchk.obj   \
        $(OBJDIR)\setjmp.obj   \
        $(OBJDIR)\setjmpex.obj \
!endif
        $(CPP_OBJDIR)\a_cmp.obj    \
        $(OBJDIR)\a_env.obj    \
        $(CPP_OBJDIR)\a_loc.obj    \
        $(CPP_OBJDIR)\a_map.obj    \
        $(CPP_OBJDIR)\a_str.obj    \
        $(OBJDIR)\abort.obj    \
        $(OBJDIR)\abs.obj      \
        $(OBJDIR)\assert.obj   \
        $(OBJDIR)\aw_com.obj   \
        $(OBJDIR)\bsearch.obj  \
        $(OBJDIR)\bsearch_s.obj \
        $(OBJDIR)\bswap.obj    \
        $(OBJDIR)\charmax.obj  \
!if "$(BLD_DLL)"!="1"
        $(OBJDIR)\cmiscdat.obj \
!endif
        $(OBJDIR)\crtmbox.obj  \
        $(OBJDIR)\crtmboxw.obj \
        $(OBJDIR)\ctype.obj    \
        $(OBJDIR)\div.obj      \
        $(CPP_OBJDIR)\dbgcalloc.obj \
        $(CPP_OBJDIR)\dbgfree.obj \
        $(CPP_OBJDIR)\dbgheap.obj \
        $(CPP_OBJDIR)\dbgmalloc.obj \
        $(CPP_OBJDIR)\dbgrealloc.obj \
        $(OBJDIR)\dbghook.obj  \
        $(OBJDIR)\dbgdel.obj   \
        $(OBJDIR)\dbgnew.obj   \
        $(OBJDIR)\dbgrpt.obj   \
        $(OBJDIR)\dbgrptt.obj  \
        $(CPP_OBJDIR)\dbgrptw.obj  \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\dbgsec.obj  \
!endif
        $(OBJDIR)\errmode.obj  \
        $(OBJDIR)\getenv.obj   \
        $(OBJDIR)\getpath.obj  \
        $(OBJDIR)\getqloc.obj  \
        $(OBJDIR)\glstatus.obj \
        $(OBJDIR)\gs_cookie.obj \
        $(OBJDIR)\gs_report.obj \
        $(OBJDIR)\gs_support.obj \
        $(OBJDIR)\initcoll.obj \
        $(OBJDIR)\initcrit.obj \
        $(OBJDIR)\initctyp.obj \
        $(OBJDIR)\inithelp.obj \
        $(OBJDIR)\initmon.obj  \
        $(OBJDIR)\initnum.obj  \
        $(OBJDIR)\inittime.obj \
        $(CPP_OBJDIR)\invarg.obj   \
        $(OBJDIR)\labs.obj     \
        $(OBJDIR)\lcnvinit.obj \
        $(OBJDIR)\lconv.obj    \
        $(OBJDIR)\ldiv.obj     \
        $(OBJDIR)\lfind.obj    \
        $(OBJDIR)\lfind_s.obj  \
        $(OBJDIR)\lsearch.obj  \
        $(OBJDIR)\lsearch_s.obj \
        $(OBJDIR)\makepath.obj \
        $(OBJDIR)\makepath_s.obj \
        $(OBJDIR)\mbtowenv.obj \
        $(OBJDIR)\onexit.obj   \
        $(OBJDIR)\nlsdata1.obj \
        $(OBJDIR)\nlsdata2.obj \
        $(OBJDIR)\nlsdata3.obj \
        $(OBJDIR)\perror.obj   \
        $(OBJDIR)\pesect.obj   \
        $(OBJDIR)\purevirt.obj \
        $(OBJDIR)\putenv.obj   \
        $(OBJDIR)\qsort.obj    \
        $(OBJDIR)\qsort_s.obj  \
        $(OBJDIR)\rand.obj     \
        $(OBJDIR)\rand_s.obj   \
        $(OBJDIR)\rotl.obj     \
        $(OBJDIR)\rotr.obj     \
        $(OBJDIR)\searchen.obj \
        $(OBJDIR)\setenv.obj   \
        $(OBJDIR)\setlocal.obj \
        $(OBJDIR)\splitpat.obj \
        $(OBJDIR)\splitpath_s.obj \
        $(OBJDIR)\_strerr.obj  \
        $(OBJDIR)\strerror.obj \
        $(OBJDIR)\syserr.obj   \
        $(OBJDIR)\convrtcp.obj \
        $(OBJDIR)\umask.obj    \
        $(CPP_OBJDIR)\w_cmp.obj    \
        $(OBJDIR)\w_env.obj    \
        $(CPP_OBJDIR)\w_loc.obj    \
        $(CPP_OBJDIR)\w_map.obj    \
        $(CPP_OBJDIR)\w_str.obj    \
        $(OBJDIR)\wassert.obj  \
        $(OBJDIR)\wcserror.obj \
        $(OBJDIR)\_wcserr.obj  \
        $(OBJDIR)\winsig.obj   \
        $(OBJDIR)\winxfltr.obj \
        $(OBJDIR)\wgetenv.obj  \
        $(OBJDIR)\wgetpath.obj \
        $(OBJDIR)\wmakepat.obj \
        $(OBJDIR)\wmakepath_s.obj \
        $(OBJDIR)\wperror.obj  \
        $(OBJDIR)\wputenv.obj  \
        $(OBJDIR)\wsearche.obj \
        $(OBJDIR)\wsetenv.obj  \
        $(OBJDIR)\wsetloca.obj \
        $(OBJDIR)\wsplitpa.obj \
        $(OBJDIR)\wsplitpath_s.obj \
        $(OBJDIR)\wrt2err.obj  \
        $(OBJDIR)\wtombenv.obj

STARTUP_OBJECTS = \
        $(OBJDIR)\_setargv.obj \
        $(OBJDIR)\_wstargv.obj \
        $(OBJDIR)\chkstk.obj   \
!if "$(TARGET_CPU)" == "i386"
        $(OBJDIR)\alloca16.obj  \
!endif
!if "$(TARGET_CPU)" == "AMD64"
        $(OBJDIR)\chkstk2.obj  \
!endif
        $(OBJDIR)\crt0.obj     \
        $(OBJDIR)\crt0dat.obj  \
        $(OBJDIR)\crt0fp.obj   \
        $(OBJDIR)\crt0init.obj \
        $(OBJDIR)\crt0msg.obj  \
        $(OBJDIR)\dllcrt0.obj  \
        $(OBJDIR)\dllmain.obj  \
        $(OBJDIR)\mlock.obj    \
        $(OBJDIR)\stdargv.obj  \
        $(OBJDIR)\stdenvp.obj  \
        $(OBJDIR)\thread.obj   \
        $(OBJDIR)\threadex.obj \
        $(OBJDIR)\tidtable.obj \
        $(OBJDIR)\tlsdtor.obj  \
        $(OBJDIR)\tlsdyn.obj   \
        $(OBJDIR)\tlssup.obj   \
        $(OBJDIR)\wcrt0.obj    \
        $(OBJDIR)\wild.obj     \
        $(OBJDIR)\wincmdln.obj \
        $(OBJDIR)\wincrt0.obj  \
        $(OBJDIR)\wstdargv.obj \
        $(OBJDIR)\wstdenvp.obj \
        $(OBJDIR)\wwncmdln.obj \
        $(OBJDIR)\wwild.obj    \
        $(OBJDIR)\wwincrt0.obj \
!if "$(TARGET_CPU)" == "i386"
        $(OBJDIR)\atlssup.obj  \
        $(OBJDIR)\fp8.obj      \
!endif
!if "$(TARGET_CPU)" == "IA64"
        $(OBJDIR)\fp8.obj      \
!endif


STDCPP_OBJECTS = \
        $(OBJDIR)\badfunction.obj \
        $(OBJDIR)\badweakptr.obj  \
        $(OBJDIR)\multprec.obj    \
        $(OBJDIR)\regex.obj       \
        $(OBJDIR)\xinvalid.obj    \
        $(OBJDIR)\xlgamma.obj     \
        $(OBJDIR)\xoutrange.obj   \
        $(OBJDIR)\xrngabort.obj   \
        $(OBJDIR)\xrngdev.obj   \
        $(OBJDIR)\cerr.obj      \
        $(OBJDIR)\cin.obj       \
        $(OBJDIR)\clog.obj      \
        $(OBJDIR)\cout.obj      \
        $(OBJDIR)\fiopen.obj    \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\instances.obj \
!endif
        $(OBJDIR)\iomanip.obj   \
        $(OBJDIR)\ios.obj       \
        $(OBJDIR)\iosptrs.obj   \
        $(OBJDIR)\iostream.obj  \
        $(OBJDIR)\locale.obj    \
        $(OBJDIR)\locale0.obj   \
        $(OBJDIR)\newaop.obj    \
        $(OBJDIR)\nomemory.obj  \
        $(OBJDIR)\nothrow.obj   \
        $(OBJDIR)\raisehan.obj  \
        $(OBJDIR)\stdhndlr.obj  \
        $(OBJDIR)\stdthrow.obj  \
        $(OBJDIR)\string.obj    \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\strstrea.obj  \
!endif
        $(OBJDIR)\ushcerr.obj   \
        $(OBJDIR)\ushcout.obj   \
        $(OBJDIR)\ushcin.obj    \
        $(OBJDIR)\ushclog.obj   \
        $(OBJDIR)\ushiostr.obj  \
        $(OBJDIR)\uncaught.obj  \
        $(OBJDIR)\wcerr.obj     \
        $(OBJDIR)\wcin.obj      \
        $(OBJDIR)\wclog.obj     \
        $(OBJDIR)\wcout.obj     \
        $(OBJDIR)\wctrans.obj   \
        $(OBJDIR)\wctype.obj    \
        $(OBJDIR)\wiostrea.obj  \
        $(OBJDIR)\wlocale.obj   \
        $(OBJDIR)\xcosh.obj     \
        $(OBJDIR)\xdateord.obj  \
        $(OBJDIR)\xdebug.obj    \
        $(OBJDIR)\xdnorm.obj    \
        $(OBJDIR)\xdscale.obj   \
        $(OBJDIR)\xdtest.obj    \
        $(OBJDIR)\xexp.obj      \
        $(OBJDIR)\xfcosh.obj    \
        $(OBJDIR)\xfdnorm.obj   \
        $(OBJDIR)\xfdscale.obj  \
        $(OBJDIR)\xfdtest.obj   \
        $(OBJDIR)\xferaise.obj  \
        $(OBJDIR)\xfexp.obj     \
        $(OBJDIR)\xfsinh.obj    \
        $(OBJDIR)\xfvalues.obj  \
        $(OBJDIR)\xgetwctype.obj\
        $(OBJDIR)\xlcosh.obj    \
        $(OBJDIR)\xldnorm.obj   \
        $(OBJDIR)\xldscale.obj  \
        $(OBJDIR)\xldtest.obj   \
        $(OBJDIR)\xlexp.obj     \
        $(OBJDIR)\xlocale.obj   \
        $(OBJDIR)\xlock.obj     \
        $(OBJDIR)\xlpoly.obj    \
        $(OBJDIR)\xlsinh.obj    \
        $(OBJDIR)\xlvalues.obj  \
        $(OBJDIR)\xmbtowc.obj   \
        $(OBJDIR)\xmtx.obj      \
        $(OBJDIR)\xmutex.obj    \
        $(OBJDIR)\xpoly.obj     \
        $(OBJDIR)\xsinh.obj     \
        $(OBJDIR)\xstod.obj     \
        $(OBJDIR)\xstof.obj     \
        $(OBJDIR)\xstol.obj     \
        $(OBJDIR)\xstold.obj    \
        $(OBJDIR)\xstoll.obj    \
        $(OBJDIR)\xstoul.obj    \
        $(OBJDIR)\xstoull.obj   \
        $(OBJDIR)\xstrcoll.obj  \
        $(OBJDIR)\xstrxfrm.obj  \
        $(OBJDIR)\xtowlower.obj \
        $(OBJDIR)\xtowupper.obj \
        $(OBJDIR)\xvalues.obj   \
        $(OBJDIR)\xwcscoll.obj  \
        $(OBJDIR)\xwcsxfrm.obj  \
        $(OBJDIR)\xwctomb.obj   \
        $(OBJDIR)\_tolower.obj  \
        $(OBJDIR)\_toupper.obj


STDIO_OBJECTS = \
        $(OBJDIR)\feoferr.obj  \
        $(OBJDIR)\fgetc.obj    \
        $(OBJDIR)\fgetchar.obj \
        $(OBJDIR)\fgets.obj    \
        $(OBJDIR)\fgetwc.obj   \
        $(OBJDIR)\fgetws.obj   \
        $(OBJDIR)\fgetwchr.obj \
        $(OBJDIR)\fileno.obj   \
        $(OBJDIR)\fputc.obj    \
        $(OBJDIR)\fputs.obj    \
        $(OBJDIR)\fputchar.obj \
        $(OBJDIR)\fputwc.obj   \
        $(OBJDIR)\fputws.obj   \
        $(OBJDIR)\fputwchr.obj \
        $(OBJDIR)\_filbuf.obj  \
        $(OBJDIR)\_filwbuf.obj \
        $(OBJDIR)\_file.obj    \
        $(OBJDIR)\_flsbuf.obj  \
        $(OBJDIR)\_flswbuf.obj \
        $(OBJDIR)\_freebuf.obj \
        $(OBJDIR)\_getbuf.obj  \
        $(OBJDIR)\_open.obj    \
        $(OBJDIR)\_sftbuf.obj  \
        $(OBJDIR)\clearerr.obj \
        $(OBJDIR)\closeall.obj \
        $(OBJDIR)\fclose.obj   \
        $(OBJDIR)\fdopen.obj   \
        $(OBJDIR)\fflush.obj   \
        $(OBJDIR)\fgetpos.obj  \
        $(OBJDIR)\fopen.obj    \
        $(OBJDIR)\fprintf.obj  \
        $(OBJDIR)\fread.obj    \
        $(OBJDIR)\freopen.obj  \
        $(OBJDIR)\fscanf.obj   \
        $(OBJDIR)\fseek.obj    \
        $(OBJDIR)\fseeki64.obj \
        $(OBJDIR)\fsetpos.obj  \
        $(OBJDIR)\ftell.obj    \
        $(OBJDIR)\ftelli64.obj \
        $(OBJDIR)\fwprintf.obj \
        $(OBJDIR)\fwrite.obj   \
        $(OBJDIR)\fwscanf.obj  \
        $(OBJDIR)\gets.obj     \
        $(OBJDIR)\getw.obj     \
        $(OBJDIR)\getws.obj    \
        $(OBJDIR)\outputformat.obj \
        $(OBJDIR)\popen.obj    \
        $(OBJDIR)\printf.obj   \
        $(OBJDIR)\puts.obj     \
        $(OBJDIR)\putw.obj     \
        $(OBJDIR)\putws.obj    \
        $(OBJDIR)\rewind.obj   \
        $(OBJDIR)\rmtmp.obj    \
        $(OBJDIR)\scanf.obj    \
        $(OBJDIR)\setmaxf.obj  \
        $(OBJDIR)\setbuf.obj   \
        $(OBJDIR)\setvbuf.obj  \
        $(OBJDIR)\snprintf.obj \
        $(OBJDIR)\snprnc.obj   \
        $(OBJDIR)\snscanf.obj  \
        $(OBJDIR)\snwprint.obj \
        $(OBJDIR)\snwscanf.obj \
        $(OBJDIR)\sprintf.obj  \
        $(OBJDIR)\sscanf.obj   \
        $(OBJDIR)\stream.obj   \
        $(OBJDIR)\swprintf.obj \
        $(OBJDIR)\swprintn.obj \
        $(OBJDIR)\swprnc.obj   \
        $(OBJDIR)\swscanf.obj  \
        $(OBJDIR)\tempnam.obj  \
        $(OBJDIR)\tmpfile.obj  \
        $(OBJDIR)\ungetc.obj   \
        $(OBJDIR)\ungetwc.obj  \
        $(OBJDIR)\vprintf.obj  \
        $(OBJDIR)\vfprintf.obj \
        $(OBJDIR)\vfwprint.obj \
        $(OBJDIR)\vsprintf.obj \
        $(OBJDIR)\vsnprint.obj \
        $(OBJDIR)\vsnprnc.obj  \
        $(OBJDIR)\vsnwprnt.obj \
        $(OBJDIR)\vswprint.obj \
        $(OBJDIR)\vswprinn.obj \
        $(OBJDIR)\vswprnc.obj  \
        $(OBJDIR)\vwprintf.obj \
        $(OBJDIR)\wfdopen.obj  \
        $(OBJDIR)\wfopen.obj   \
        $(OBJDIR)\wfreopen.obj \
        $(OBJDIR)\_wopen.obj   \
        $(OBJDIR)\wpopen.obj   \
        $(OBJDIR)\wprintf.obj  \
        $(OBJDIR)\wscanf.obj   \
        $(OBJDIR)\wtempnam.obj \
        $(OBJDIR)\wtmpfile.obj \
        $(OBJDIR)\ncommode.obj \
        $(CPP_OBJDIR)\cscanf.obj   \
        $(CPP_OBJDIR)\cscanfs.obj  \
        $(CPP_OBJDIR)\cwscanf.obj  \
        $(CPP_OBJDIR)\cwscanfs.obj \
        $(CPP_OBJDIR)\cprintf.obj  \
        $(CPP_OBJDIR)\cprintfp.obj \
        $(CPP_OBJDIR)\cprintfs.obj \
        $(CPP_OBJDIR)\cwprintf.obj \
        $(CPP_OBJDIR)\cwprntfp.obj \
        $(CPP_OBJDIR)\cwprntfs.obj \
        $(CPP_OBJDIR)\input.obj    \
        $(CPP_OBJDIR)\inputs.obj   \
        $(CPP_OBJDIR)\output.obj   \
        $(CPP_OBJDIR)\outputp.obj  \
        $(CPP_OBJDIR)\outputs.obj  \
        $(CPP_OBJDIR)\winput.obj   \
        $(CPP_OBJDIR)\winputs.obj  \
        $(CPP_OBJDIR)\woutput.obj  \
        $(CPP_OBJDIR)\woutputp.obj \
        $(CPP_OBJDIR)\woutputs.obj

STRING_OBJECTS = \
!if "$(TARGET_CPU)" == "IA64"
        $(OBJDIR)\memccpy.obj  \
        $(OBJDIR)\memchr.obj   \
        $(OBJDIR)\memcmp.obj   \
        $(OBJDIR)\memcpy.obj   \
        $(OBJDIR)\memcpy_s.obj \
        $(OBJDIR)\memcpyi.obj  \
        $(OBJDIR)\memmove.obj  \
        $(OBJDIR)\memmove_s.obj \
        $(OBJDIR)\memset.obj   \
        $(OBJDIR)\memseti.obj  \
        $(OBJDIR)\strcat.obj   \
        $(OBJDIR)\strchr.obj   \
        $(OBJDIR)\strcmp.obj   \
        $(OBJDIR)\strcpy.obj   \
        $(OBJDIR)\strcspn.obj  \
        $(OBJDIR)\strdup.obj   \
        $(OBJDIR)\strlen.obj   \
        $(OBJDIR)\strncat.obj  \
        $(OBJDIR)\strncmp.obj  \
        $(OBJDIR)\strncpy.obj  \
        $(OBJDIR)\strnset.obj  \
        $(OBJDIR)\strpbrk.obj  \
        $(OBJDIR)\strrchr.obj  \
        $(OBJDIR)\strrev.obj   \
        $(OBJDIR)\strset.obj   \
        $(OBJDIR)\strspn.obj   \
        $(OBJDIR)\strstr.obj   \
!endif
!if "$(TARGET_CPU)" == "i386"
        $(OBJDIR)\memcpy.obj   \
        $(OBJDIR)\p4_memcpy.obj \
        $(OBJDIR)\memcpy_s.obj \
        $(OBJDIR)\memchr.obj   \
        $(OBJDIR)\memcmp.obj   \
        $(OBJDIR)\memccpy.obj  \
        $(OBJDIR)\_memicmp.obj \
        $(OBJDIR)\memmove.obj  \
        $(OBJDIR)\memmove_s.obj \
        $(OBJDIR)\memset.obj   \
        $(OBJDIR)\p4_memset.obj \
        $(OBJDIR)\strcat.obj   \
        $(OBJDIR)\strchr.obj   \
        $(OBJDIR)\strcmp.obj   \
        $(OBJDIR)\strcspn.obj  \
        $(OBJDIR)\strdup.obj   \
        $(OBJDIR)\strlen.obj   \
        $(OBJDIR)\strncat.obj  \
        $(OBJDIR)\strncmp.obj  \
        $(OBJDIR)\strncpy.obj  \
        $(OBJDIR)\_strnicm.obj \
        $(OBJDIR)\strnset.obj  \
        $(OBJDIR)\strpbrk.obj  \
        $(OBJDIR)\strrchr.obj  \
        $(OBJDIR)\strrev.obj   \
        $(OBJDIR)\strset.obj   \
        $(OBJDIR)\strspn.obj   \
        $(OBJDIR)\strstr.obj   \
!endif
!if "$(TARGET_CPU)" == "AMD64"
# memcpy.obj contains memmove as well
        $(OBJDIR)\memcpy.obj   \
        $(OBJDIR)\memcpy_s.obj \
        $(OBJDIR)\memchr.obj   \
        $(OBJDIR)\memcmp.obj   \
        $(OBJDIR)\memccpy.obj  \
        $(OBJDIR)\memmove_s.obj \
        $(OBJDIR)\memset.obj   \
        $(OBJDIR)\strcat.obj   \
        $(OBJDIR)\strchr.obj   \
        $(OBJDIR)\strcmp.obj   \
        $(OBJDIR)\strcspn.obj  \
        $(OBJDIR)\strdup.obj   \
        $(OBJDIR)\strlen.obj   \
        $(OBJDIR)\strncat.obj  \
        $(OBJDIR)\strncmp.obj  \
        $(OBJDIR)\strncpy.obj  \
        $(OBJDIR)\strnset.obj  \
        $(OBJDIR)\strpbrk.obj  \
        $(OBJDIR)\strrchr.obj  \
        $(OBJDIR)\strrev.obj   \
        $(OBJDIR)\strset.obj   \
        $(OBJDIR)\strspn.obj   \
        $(OBJDIR)\strstr.obj   \
!endif
        $(OBJDIR)\strlen_s.obj \
        $(OBJDIR)\strcat_s.obj \
        $(OBJDIR)\strncat_s.obj \
        $(OBJDIR)\strcpy_s.obj \
        $(OBJDIR)\strncpy_s.obj \
        $(OBJDIR)\strncnt.obj  \
        $(OBJDIR)\strset_s.obj \
        $(OBJDIR)\strnset_s.obj \
        $(OBJDIR)\strtok.obj   \
        $(OBJDIR)\strtok_s.obj \
        $(OBJDIR)\wcscat.obj   \
        $(OBJDIR)\wcscat_s.obj \
        $(OBJDIR)\wcschr.obj   \
        $(OBJDIR)\wcscmp.obj   \
        $(OBJDIR)\wcscpy_s.obj \
        $(OBJDIR)\wcscspn.obj  \
        $(OBJDIR)\wcsdup.obj   \
        $(OBJDIR)\wcslen.obj   \
        $(OBJDIR)\wcslen_s.obj \
        $(OBJDIR)\wcsncat.obj  \
        $(OBJDIR)\wcsncat_s.obj \
        $(OBJDIR)\wcsncmp.obj  \
        $(OBJDIR)\wcsncnt.obj  \
        $(OBJDIR)\wcsncpy.obj  \
        $(OBJDIR)\wcsncpy_s.obj  \
        $(OBJDIR)\wcsnset.obj  \
        $(OBJDIR)\wcsnset_s.obj  \
        $(OBJDIR)\wcspbrk.obj  \
        $(OBJDIR)\wcsrchr.obj  \
        $(OBJDIR)\wcsrev.obj   \
        $(OBJDIR)\wcsset.obj   \
        $(OBJDIR)\wcsset_s.obj \
        $(OBJDIR)\wcsspn.obj   \
        $(OBJDIR)\wcsstr.obj   \
        $(OBJDIR)\wcstok.obj   \
        $(OBJDIR)\wcstok_s.obj \
        $(CPP_OBJDIR)\memicmp.obj  \
        $(CPP_OBJDIR)\strcoll.obj  \
        $(CPP_OBJDIR)\stricmp.obj  \
        $(CPP_OBJDIR)\stricoll.obj \
        $(CPP_OBJDIR)\strlwr.obj   \
        $(CPP_OBJDIR)\strncoll.obj \
        $(CPP_OBJDIR)\strnicmp.obj \
        $(CPP_OBJDIR)\strnicol.obj \
        $(CPP_OBJDIR)\strupr.obj   \
        $(CPP_OBJDIR)\strxfrm.obj  \
        $(CPP_OBJDIR)\wcscoll.obj  \
        $(CPP_OBJDIR)\wcsicmp.obj  \
        $(CPP_OBJDIR)\wcsicoll.obj \
        $(CPP_OBJDIR)\wcslwr.obj   \
        $(CPP_OBJDIR)\wcsncoll.obj \
        $(CPP_OBJDIR)\wcsnicmp.obj \
        $(CPP_OBJDIR)\wcsnicol.obj \
        $(CPP_OBJDIR)\wcsupr.obj   \
        $(CPP_OBJDIR)\wcsxfrm.obj 

TIME_OBJECTS = \
        $(OBJDIR)\asctime.obj  \
        $(OBJDIR)\clock.obj    \
        $(OBJDIR)\ctime.obj    \
        $(OBJDIR)\days.obj     \
        $(OBJDIR)\difftime.obj \
        $(OBJDIR)\difftm64.obj \
        $(OBJDIR)\dtoxtime.obj \
        $(OBJDIR)\ftime.obj    \
        $(OBJDIR)\gmtime.obj   \
        $(OBJDIR)\localtim.obj \
        $(OBJDIR)\mktime.obj   \
        $(CPP_OBJDIR)\strftime.obj \
        $(OBJDIR)\strdate.obj  \
        $(OBJDIR)\strtime.obj  \
        $(OBJDIR)\time.obj     \
        $(OBJDIR)\timeset.obj  \
        $(OBJDIR)\tzset.obj    \
        $(OBJDIR)\utime.obj    \
        $(OBJDIR)\ctime64.obj  \
        $(OBJDIR)\dtoxtm64.obj \
        $(OBJDIR)\ftime64.obj  \
        $(OBJDIR)\gmtime64.obj \
        $(OBJDIR)\loctim64.obj \
        $(OBJDIR)\mktime64.obj \
        $(OBJDIR)\systime.obj  \
        $(OBJDIR)\time64.obj   \
        $(OBJDIR)\utime64.obj  \
        $(CPP_OBJDIR)\wcsftime.obj \
        $(OBJDIR)\wasctime.obj \
        $(OBJDIR)\wctime.obj   \
        $(OBJDIR)\wctime64.obj \
        $(OBJDIR)\wstrdate.obj \
        $(OBJDIR)\wstrtime.obj \
        $(OBJDIR)\wutime.obj   \
        $(OBJDIR)\wutime64.obj

$(OBJDIR)\convert.lib: $(CONVERT_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(CONVERT_OBJECTS: =^
)
<<keep


$(OBJDIR)\direct.lib: $(DIRECT_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(DIRECT_OBJECTS: =^
)
<<keep


$(OBJDIR)\dllstuff.lib: $(DLLSTUFF_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(DLLSTUFF_OBJECTS: =^
)
<<keep


$(OBJDIR)\dos.lib: $(DOS_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(DOS_OBJECTS: =^
)
<<keep


$(OBJDIR)\exec.lib: $(EXEC_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(EXEC_OBJECTS: =^
)
<<keep


$(OBJDIR)\heap.lib: $(HEAP_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(HEAP_OBJECTS: =^
)
<<keep


$(OBJDIR)\helper.lib: $(HELPER_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(HELPER_OBJECTS: =^
)
<<keep


$(OBJDIR)\linkopts.lib: $(LINKOPTS_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(LINKOPTS_OBJECTS: =^
)
<<keep

$(OBJDIR)\plinkopts.lib: $(PLINKOPTS_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(PLINKOPTS_OBJECTS: =^
)
<<keep

$(OBJDIR)\lowio.lib: $(LOWIO_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(LOWIO_OBJECTS: =^
)
<<keep


$(OBJDIR)\mbstring.lib: $(MBSTRING_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(MBSTRING_OBJECTS: =^
)
<<keep


$(OBJDIR)\misc.lib: $(MISC_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(MISC_OBJECTS: =^
)
<<keep


!if "$(BLD_DLL)"=="1"
$(OBJDIR)\startup.lib: $(STARTUP_OBJECTS)
!else
$(OBJDIR)\startup.lib: $(STARTUP_OBJECTS)
!endif
    $(LIB) -out:$@ @<<$*.rsp
$(STARTUP_OBJECTS: =^
)
<<keep


$(OBJDIR)\$(STDCPP_SRC).lib: $(STDCPP_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(STDCPP_OBJECTS: =^
)
<<keep


$(OBJDIR)\stdio.lib: $(STDIO_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(STDIO_OBJECTS: =^
)
<<keep


$(OBJDIR)\string.lib: $(STRING_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(STRING_OBJECTS: =^
)
<<keep


$(OBJDIR)\time.lib: $(TIME_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(TIME_OBJECTS: =^
)
<<keep


$(OBJDIR)\eh.lib: $(PREOBJDIR)\eh.lib
        copy $(PREOBJDIR)\eh.lib $@

$(OBJDIR)\unhandld.obj: $(PREOBJDIR)\unhandld.obj
        copy $(PREOBJDIR)\unhandld.obj $@

!if "$(RTC)"=="YES"
$(OBJDIR)\rtc.lib: $(PREOBJDIR)\rtc.lib
        copy $(PREOBJDIR)\rtc.lib $@
!endif

$(OBJDIR)\conv.lib: $(PREOBJDIR)\conv.lib
        copy $(PREOBJDIR)\conv.lib $@

$(OBJDIR)\tran.lib: $(PREOBJDIR)\tran.lib
        copy $(PREOBJDIR)\tran.lib $@

$(OBJDIR)\chkesp.obj: $(PREOBJDIR)\chkesp.obj
        copy $(PREOBJDIR)\chkesp.obj $@

$(OBJDIR)\rtcmd.obj: $(PREOBJDIR)\rtcmd.obj
        copy $(PREOBJDIR)\rtcmd.obj $@

$(OBJDIR)\ehvccctr.obj: $(PREOBJDIR)\ehvccctr.obj
        copy $(PREOBJDIR)\ehvccctr.obj $@

$(OBJDIR)\ehvcccvb.obj: $(PREOBJDIR)\ehvcccvb.obj
        copy $(PREOBJDIR)\ehvcccvb.obj $@

$(OBJDIR)\ehvecctr.obj: $(PREOBJDIR)\ehvecctr.obj
        copy $(PREOBJDIR)\ehvecctr.obj $@

$(OBJDIR)\ehveccvb.obj: $(PREOBJDIR)\ehveccvb.obj
        copy $(PREOBJDIR)\ehveccvb.obj $@

$(OBJDIR)\ehvecdtr.obj: $(PREOBJDIR)\ehvecdtr.obj
        copy $(PREOBJDIR)\ehvecdtr.obj $@

# !if "$(BLD_SYSCRT)" != "1"

$(OBJDIR)\tncleanup.obj: $(PREOBJDIR)\tncleanup.obj
        copy $(PREOBJDIR)\tncleanup.obj $@

$(OBJDIR)\oldexcpt.obj: $(PREOBJDIR)\oldexcpt.obj
        copy $(PREOBJDIR)\oldexcpt.obj $@

$(OBJDIR)\sehprolg.obj: $(PREOBJDIR)\sehprolg.obj
        copy $(PREOBJDIR)\sehprolg.obj $@

$(OBJDIR)\sehprolg4.obj: $(PREOBJDIR)\sehprolg4.obj
        copy $(PREOBJDIR)\sehprolg4.obj $@

$(OBJDIR)\sehprolg4gs.obj: $(PREOBJDIR)\sehprolg4gs.obj
        copy $(PREOBJDIR)\sehprolg4gs.obj $@

$(OBJDIR)\sehsupp.obj: $(PREOBJDIR)\sehsupp.obj
        copy $(PREOBJDIR)\sehsupp.obj $@

$(OBJDIR)\calldtor.obj: $(PREOBJDIR)\calldtor.obj
        copy $(PREOBJDIR)\calldtor.obj $@

$(OBJDIR)\setjmp.obj: $(PREOBJDIR)\setjmp.obj
        copy $(PREOBJDIR)\setjmp.obj $@

!if "$(TARGET_CPU)" == "i386"

$(OBJDIR)\atlssup.obj: $(PREOBJDIR)\atlssup.obj
        copy $(PREOBJDIR)\atlssup.obj $@

$(OBJDIR)\bsku.obj: $(PREOBJDIR)\bsku.obj
        copy $(PREOBJDIR)\bsku.obj $@

$(OBJDIR)\chandler4.obj: $(PREOBJDIR)\chandler4.obj
        copy $(PREOBJDIR)\chandler4.obj $@

$(OBJDIR)\chandler4gs.obj: $(PREOBJDIR)\chandler4gs.obj
        copy $(PREOBJDIR)\chandler4gs.obj $@

$(OBJDIR)\ehprolg2.obj: $(PREOBJDIR)\ehprolg2.obj
        copy $(PREOBJDIR)\ehprolg2.obj $@

$(OBJDIR)\ehprolg3.obj: $(PREOBJDIR)\ehprolg3.obj
        copy $(PREOBJDIR)\ehprolg3.obj $@

$(OBJDIR)\ehprolg3a.obj: $(PREOBJDIR)\ehprolg3a.obj
        copy $(PREOBJDIR)\ehprolg3a.obj $@

$(OBJDIR)\ehprolog.obj: $(PREOBJDIR)\ehprolog.obj
        copy $(PREOBJDIR)\ehprolog.obj $@

$(OBJDIR)\eh3valid.obj: $(PREOBJDIR)\eh3valid.obj
        copy $(PREOBJDIR)\eh3valid.obj $@

$(OBJDIR)\exsup.obj: $(PREOBJDIR)\exsup.obj
        copy $(PREOBJDIR)\exsup.obj $@

$(OBJDIR)\exsup2.obj: $(PREOBJDIR)\exsup2.obj
        copy $(PREOBJDIR)\exsup2.obj $@

$(OBJDIR)\exsup3.obj: $(PREOBJDIR)\exsup3.obj
        copy $(PREOBJDIR)\exsup3.obj $@

$(OBJDIR)\exsup4.obj: $(PREOBJDIR)\exsup4.obj
        copy $(PREOBJDIR)\exsup4.obj $@

$(OBJDIR)\cpu_disp.obj: $(PREOBJDIR)\cpu_disp.obj
        copy $(PREOBJDIR)\cpu_disp.obj $@

$(OBJDIR)\ftol2.obj: $(PREOBJDIR)\ftol2.obj
        copy $(PREOBJDIR)\ftol2.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

$(OBJDIR)\memcmp.obj: $(PREOBJDIR)\memcmp.obj
        copy $(PREOBJDIR)\memcmp.obj $@

$(OBJDIR)\p4_memcpy.obj: $(PREOBJDIR)\p4_memcpy.obj
        copy $(PREOBJDIR)\p4_memcpy.obj $@

$(OBJDIR)\p4_memset.obj: $(PREOBJDIR)\p4_memset.obj
        copy $(PREOBJDIR)\p4_memset.obj $@

$(OBJDIR)\setjmp3.obj: $(PREOBJDIR)\setjmp3.obj
        copy $(PREOBJDIR)\setjmp3.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

########
#
# These objects can be built from (assembler) source by editing
# makefile.sub so that the symbol BLD_ASM is set to the value 1.
# To assembler these objects, you must have MASM 6.11a or later.
#
########

!if "$(BLD_ASM)"=="0"

$(OBJDIR)\alloca16.obj: $(PREOBJDIR)\alloca16.obj
        copy $(PREOBJDIR)\alloca16.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\dllsupp.obj: $(PREOBJDIR)\dllsupp.obj
        copy $(PREOBJDIR)\dllsupp.obj $@

$(OBJDIR)\enable.obj: $(PREOBJDIR)\enable.obj
        copy $(PREOBJDIR)\enable.obj $@

$(OBJDIR)\inp.obj: $(PREOBJDIR)\inp.obj
        copy $(PREOBJDIR)\inp.obj $@

$(OBJDIR)\lldiv.obj: $(PREOBJDIR)\lldiv.obj
        copy $(PREOBJDIR)\lldiv.obj $@

$(OBJDIR)\lldvrm.obj: $(PREOBJDIR)\lldvrm.obj
        copy $(PREOBJDIR)\lldvrm.obj $@

$(OBJDIR)\llmul.obj: $(PREOBJDIR)\llmul.obj
        copy $(PREOBJDIR)\llmul.obj $@

$(OBJDIR)\llrem.obj: $(PREOBJDIR)\llrem.obj
        copy $(PREOBJDIR)\llrem.obj $@

$(OBJDIR)\llshl.obj: $(PREOBJDIR)\llshl.obj
        copy $(PREOBJDIR)\llshl.obj $@

$(OBJDIR)\llshr.obj: $(PREOBJDIR)\llshr.obj
        copy $(PREOBJDIR)\llshr.obj $@

$(OBJDIR)\memccpy.obj: $(PREOBJDIR)\memccpy.obj
        copy $(PREOBJDIR)\memccpy.obj $@

$(OBJDIR)\memchr.obj: $(PREOBJDIR)\memchr.obj
        copy $(PREOBJDIR)\memchr.obj $@

$(OBJDIR)\memcpy.obj: $(PREOBJDIR)\memcpy.obj
        copy $(PREOBJDIR)\memcpy.obj $@

$(OBJDIR)\_memicmp.obj: $(PREOBJDIR)\_memicmp.obj
        copy $(PREOBJDIR)\_memicmp.obj $@

$(OBJDIR)\memmove.obj: $(PREOBJDIR)\memmove.obj
        copy $(PREOBJDIR)\memmove.obj $@

$(OBJDIR)\memset.obj: $(PREOBJDIR)\memset.obj
        copy $(PREOBJDIR)\memset.obj $@

$(OBJDIR)\outp.obj: $(PREOBJDIR)\outp.obj
        copy $(PREOBJDIR)\outp.obj $@

$(OBJDIR)\strcat.obj: $(PREOBJDIR)\strcat.obj
        copy $(PREOBJDIR)\strcat.obj $@

$(OBJDIR)\strchr.obj: $(PREOBJDIR)\strchr.obj
        copy $(PREOBJDIR)\strchr.obj $@

$(OBJDIR)\strcmp.obj: $(PREOBJDIR)\strcmp.obj
        copy $(PREOBJDIR)\strcmp.obj $@

$(OBJDIR)\strcspn.obj: $(PREOBJDIR)\strcspn.obj
        copy $(PREOBJDIR)\strcspn.obj $@

$(OBJDIR)\strlen.obj: $(PREOBJDIR)\strlen.obj
        copy $(PREOBJDIR)\strlen.obj $@

$(OBJDIR)\strncat.obj: $(PREOBJDIR)\strncat.obj
        copy $(PREOBJDIR)\strncat.obj $@

$(OBJDIR)\strncpy.obj: $(PREOBJDIR)\strncpy.obj
        copy $(PREOBJDIR)\strncpy.obj $@

$(OBJDIR)\_strnicm.obj: $(PREOBJDIR)\_strnicm.obj
        copy $(PREOBJDIR)\_strnicm.obj $@

$(OBJDIR)\strnset.obj: $(PREOBJDIR)\strnset.obj
        copy $(PREOBJDIR)\strnset.obj $@

$(OBJDIR)\strpbrk.obj: $(PREOBJDIR)\strpbrk.obj
        copy $(PREOBJDIR)\strpbrk.obj $@

$(OBJDIR)\strrchr.obj: $(PREOBJDIR)\strrchr.obj
        copy $(PREOBJDIR)\strrchr.obj $@

$(OBJDIR)\strrev.obj: $(PREOBJDIR)\strrev.obj
        copy $(PREOBJDIR)\strrev.obj $@

$(OBJDIR)\strset.obj: $(PREOBJDIR)\strset.obj
        copy $(PREOBJDIR)\strset.obj $@

$(OBJDIR)\strspn.obj: $(PREOBJDIR)\strspn.obj
        copy $(PREOBJDIR)\strspn.obj $@

$(OBJDIR)\strstr.obj: $(PREOBJDIR)\strstr.obj
        copy $(PREOBJDIR)\strstr.obj $@

$(OBJDIR)\ulldiv.obj: $(PREOBJDIR)\ulldiv.obj
        copy $(PREOBJDIR)\ulldiv.obj $@

$(OBJDIR)\ulldvrm.obj: $(PREOBJDIR)\ulldvrm.obj
        copy $(PREOBJDIR)\ulldvrm.obj $@

$(OBJDIR)\ullrem.obj: $(PREOBJDIR)\ullrem.obj
        copy $(PREOBJDIR)\ullrem.obj $@

$(OBJDIR)\ullshr.obj    : $(PREOBJDIR)\ullshr.obj
        copy $(PREOBJDIR)\ullshr.obj $@

!endif # BLD_ASM==0
!endif # TARGET_CPU == i386

!if "$(TARGET_CPU)" == "IA64"

$(OBJDIR)\chandler.obj: $(PREOBJDIR)\chandler.obj
        copy $(PREOBJDIR)\chandler.obj $@

$(OBJDIR)\cinitone.obj: $(PREOBJDIR)\cinitone.obj
        copy $(PREOBJDIR)\cinitone.obj $@

$(OBJDIR)\gshandler.obj: $(PREOBJDIR)\gshandler.obj
        copy $(PREOBJDIR)\gshandler.obj $@

$(OBJDIR)\gshandlereh.obj: $(PREOBJDIR)\gshandlereh.obj
        copy $(PREOBJDIR)\gshandlereh.obj $@

$(OBJDIR)\gshandlerseh.obj: $(PREOBJDIR)\gshandlerseh.obj
        copy $(PREOBJDIR)\gshandlerseh.obj $@

$(OBJDIR)\jmpuwind.obj: $(PREOBJDIR)\jmpuwind.obj
        copy $(PREOBJDIR)\jmpuwind.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\miscs.obj: $(PREOBJDIR)\miscs.obj
        copy $(PREOBJDIR)\miscs.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

$(OBJDIR)\strcat.obj: $(PREOBJDIR)\strcat.obj
        copy $(PREOBJDIR)\strcat.obj $@

$(OBJDIR)\strcpy.obj: $(PREOBJDIR)\strcpy.obj
        copy $(PREOBJDIR)\strcpy.obj $@

$(OBJDIR)\strcmp.obj: $(PREOBJDIR)\strcmp.obj
        copy $(PREOBJDIR)\strcmp.obj $@

$(OBJDIR)\strlen.obj: $(PREOBJDIR)\strlen.obj
        copy $(PREOBJDIR)\strlen.obj $@

$(OBJDIR)\memcmp.obj: $(PREOBJDIR)\memcmp.obj
        copy $(PREOBJDIR)\memcmp.obj $@

$(OBJDIR)\memcpy.obj: $(PREOBJDIR)\memcpy.obj
        copy $(PREOBJDIR)\memcpy.obj $@

$(OBJDIR)\memcpyi.obj: $(PREOBJDIR)\memcpyi.obj
        copy $(PREOBJDIR)\memcpyi.obj $@

$(OBJDIR)\memmove.obj: $(PREOBJDIR)\memmove.obj
        copy $(PREOBJDIR)\memmove.obj $@

$(OBJDIR)\memset.obj: $(PREOBJDIR)\memset.obj
        copy $(PREOBJDIR)\memset.obj $@

$(OBJDIR)\memseti.obj: $(PREOBJDIR)\memseti.obj
        copy $(PREOBJDIR)\memseti.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

!endif
!if "$(TARGET_CPU)"=="AMD64"
$(OBJDIR)\jmpuwind.obj: $(PREOBJDIR)\jmpuwind.obj
        copy $(PREOBJDIR)\jmpuwind.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

$(OBJDIR)\amdsecgs.obj: $(PREOBJDIR)\amdsecgs.obj
        copy $(PREOBJDIR)\amdsecgs.obj $@

$(OBJDIR)\chandler.obj: $(PREOBJDIR)\chandler.obj
        copy $(PREOBJDIR)\chandler.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\chkstk2.obj: $(PREOBJDIR)\chkstk2.obj
        copy $(PREOBJDIR)\chkstk2.obj $@

$(OBJDIR)\gshandler.obj: $(PREOBJDIR)\gshandler.obj
        copy $(PREOBJDIR)\gshandler.obj $@

$(OBJDIR)\gshandlereh.obj: $(PREOBJDIR)\gshandlereh.obj
        copy $(PREOBJDIR)\gshandlereh.obj $@

$(OBJDIR)\gshandlerseh.obj: $(PREOBJDIR)\gshandlerseh.obj
        copy $(PREOBJDIR)\gshandlerseh.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

!endif

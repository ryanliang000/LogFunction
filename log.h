/*
 * logfunction 
 *
 * Copyright (c) 2020 Rain
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modifica-
 * tion, are permitted provided that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *   2.  Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MER-
 * CHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTH-
 * ERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License ("GPL") version 2 or any later version,
 * in which case the provisions of the GPL are applicable instead of
 * the above. If you wish to allow the use of your version of this file
 * only under the terms of the GPL and not to allow others to use your
 * version of this file under the BSD license, indicate your decision
 * by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL. If you do not delete the
 * provisions above, a recipient may use your version of this file under
 * either the BSD or the GPL.
 */
#ifndef _LOG_FUNCTION_LOG_H_
#define _LOG_FUNCTION_LOG_H_
#include <stdio.h>
#include <string.h>

#ifndef _LOG_BASE_FUNC
#define _LOG_BASE_FUNC
#define _LOG_BASE(fd, title, ...)\
	fprintf(fd, title);\
	fprintf(fd, __VA_ARGS__);\
	fprintf(fd, " (line:%d)\n", __LINE__);
#define _LOG_BASE_PURE(...)\
    fprintf(stdout, __VA_ARGS__);\
	fprintf(stdout, "\n");
#endif

#if defined REL
	#define LOG_E(...) _LOG_BASE(stderr, "[ERR]", __VA_ARGS__)
	#define LOG_R(...)
	#define LOG_I(...)
	#define LOG(...)
#elif defined RUN
	#define LOG_E(...) _LOG_BASE(stderr, "[ERR]", __VA_ARGS__)
	#define LOG_R(...) _LOG_BASE(stdout, "[RUN]", __VA_ARGS__)
	#define LOG_I(...)
	#define LOG(...)
#else
	#define LOG_E(...) _LOG_BASE(stderr, "[ERR]", __VA_ARGS__)
	#define LOG_R(...) _LOG_BASE(stdout, "[RUN]", __VA_ARGS__) 
	#define LOG_I(...) _LOG_BASE(stdout, "[INF]", __VA_ARGS__)
	#define LOG(...)   _LOG_BASE_PURE(__VA_ARGS__)
#endif

#ifdef DBG
	#define LOG_D(...) LOG_BASE(stdout, "[DBG]", __VA_ARGS__)
#else
	#define LOG_D(...)
#endif

#endif

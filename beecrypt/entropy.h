/*
 * Copyright (c) 1998, 1999, 2000, 2001, 2002 Virtual Unlimited B.V.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*!\file entropy.h
 * \brief Entropy sources, headers.
 * \author Bob Deblier <bob.deblier@pandora.be>
 * \ingroup ES_m ES_audio_m ES_dsp_m ES_random_m ES_urandom_m ES_tty_m
 */

#ifndef _ENTROPY_H
#define _ENTROPY_H

#include "beecrypt.h"

#if WIN32
#include <Windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WIN32
BEECRYPTAPI
int entropy_provider_setup(HINSTANCE);
BEECRYPTAPI
int entropy_provider_cleanup(void);

BEECRYPTAPI
int entropy_wavein(byte* data, size_t size);
BEECRYPTAPI
int entropy_console(byte* data, size_t size);
BEECRYPTAPI
int entropy_wincrypt(byte* data, size_t size);
#else

#if HAVE_DEV_AUDIO
/** \ingroup ES_audio_m ES_m
 */
int entropy_dev_audio (/*@out@*/ byte* data, size_t size)
	/*@globals fileSystem, internalState @*/
	/*@modifies data, fileSystem, internalState @*/;
#endif

#if HAVE_DEV_DSP
/** \ingroup ES_dsp_m ES_m
 */
int entropy_dev_dsp   (/*@out@*/ byte* data, size_t size)
	/*@globals fileSystem, internalState @*/
	/*@modifies data, fileSystem, internalState @*/;
#endif

#if HAVE_DEV_RANDOM
/** \ingroup ES_random_m ES_m
 */
int entropy_dev_random(/*@out@*/ byte* data, size_t size)
	/*@globals fileSystem, internalState @*/
	/*@modifies data, fileSystem, internalState @*/;
#endif

#if HAVE_DEV_URANDOM
/** \ingroup ES_urandom_m ES_m
 */
int entropy_dev_urandom(/*@out@*/ byte* data, size_t size)
	/*@globals fileSystem, internalState @*/
	/*@modifies data, fileSystem, internalState @*/;
#endif

#if HAVE_DEV_TTY
/** \ingroup ES_tty_m ES_m
 */
int entropy_dev_tty   (/*@out@*/ byte* data, size_t size)
	/*@globals fileSystem, internalState @*/
	/*@modifies data, fileSystem, internalState @*/;
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif

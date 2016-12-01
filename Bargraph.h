/**************************************************************************/
/*!
    @file     Button.cpp
    @author   Jason Scheunemann <jason.scheunemann@gmail.com>
    @section LICENSE
    Software License Agreement (BSD License)
    Copyright (c) 2016, Jason Scheunemann
    All rights reserved.
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef Bargraph_h
#define Bargraph_h

#include <Arduino.h>
#include <Adafruit_LEDBackpack.h>

#define DEFAULT_SEGMENT_COUNT 24
#define DEFAULT_ADDR 0x70

class Bargraph {
  public:
    Bargraph::Bargraph();
    Bargraph::Bargraph(uint8_t addr);
    Bargraph::Bargraph(uint8_t addr, uint8_t segmentCount);
    void Bargraph::begin(void);
    void Bargraph::output(char output[]);
    void Bargraph::setFormat(char format[]);
    void Bargraph::formattedOutput(char output[]);
    void Bargraph::formattedOutput(char format[], char output[]);
    void Bargraph::clear(void);
  protected:
    uint8_t i2c_addr;
    uint8_t _segments;
    char _format[];
    char _output[];
    Adafruit_Bargraph bar;
};


#endif

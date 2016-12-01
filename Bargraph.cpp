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

#include "Bargraph.h"

Bargraph::Bargraph() {
  this->i2c_addr = DEFAULT_ADDR;
  this->_segments = DEFAULT_SEGMENT_COUNT;
}

Bargraph::Bargraph(uint8_t addr) {
  this->i2c_addr = addr;
}

Bargraph::Bargraph(uint8_t addr, uint8_t segmentCount) {
  this->i2c_addr = addr;
  this->_segments = segmentCount;
}

void Bargraph::begin(void) {
  this->bar = Adafruit_Bargraph();
  this->bar.begin(this->i2c_addr);
}

void Bargraph::setFormat(char format[]) {
  sprintf(this->_format, format);
}

void Bargraph::formattedOutput(char output[]) {
  this->formattedOutput(this->_format, output);
}

void Bargraph::formattedOutput(char format[], char output[]) {
  for (int i = 0; i < this->_segments; i++) {
    uint8_t color = LED_OFF;

    switch (format[i]) {
      case 'G':
        if (output[i] == '1') color = LED_GREEN;
        break;
      case 'Y':
        if (output[i] == '1') color = LED_YELLOW;
        break;
      case 'R':
        if (output[i] == '1') color = LED_RED;
        break;
    }

    bar.setBar(this->_segments - i - 1, color);
  }

  this->bar.writeDisplay();
}

void Bargraph::output(char output[]) {
  char segments[this->_segments + 1];
  memset(segments, '1', this->_segments);
  segments[this->_segments + 1] = '\0';
  this->formattedOutput(output, segments);
}

void Bargraph::clear(void) {
  char segments[this->_segments + 1];
  memset(segments, '-', this->_segments);
  segments[this->_segments + 1] = '\0';

  this->output(segments);
}

/**
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

window.addEventListener('load', function() {
  var form = document.getElementById("controls-form");
  form.addEventListener('submit', function(e) {
    e.preventDefault();
  });

  var timestampInput = document.getElementById("timestamp-input");
  timestampInput.addEventListener('change', function(e) {
    rockySimulator.setTime(Number(e.target.value) * 1000);
  });

  var timezoneSlider = document.getElementById("timezone-offset-input");
  var timezoneSpan = document.getElementById("timezone-offset-span");
  var timezoneSliderOnChange = function() {
    var offset = timezoneSlider.value;
    rockySimulator.setTimezoneOffset(offset);
    var sign;
    if (offset > 0) {
      sign = '+';
    } else if (offset < 0) {
      sign = '-';
    } else {
      sign = '';
    }
    var offsetMinutes = (offset % 60);
    var absOffsetHours = Math.abs((offset - offsetMinutes) / 60);
    var gmtText = 'GMT ' + sign + absOffsetHours;
    if (offsetMinutes) {
      var absOffsetMinutes = Math.abs(offsetMinutes);
      gmtText += ':' + (absOffsetMinutes < 10 ? '0' : '') + absOffsetMinutes;
    }
    timezoneSpan.innerText = gmtText;
  };
  timezoneSlider.addEventListener('change', timezoneSliderOnChange);
  timezoneSlider.addEventListener('input', timezoneSliderOnChange);

  // After loading the page, set the slider to the local TZ:
  var localTimezoneOffset = new Date().getTimezoneOffset();
  timezoneSlider.value = localTimezoneOffset;
  timezoneSliderOnChange();

  var time24hStyle = document.getElementById("24h-style-input");
  time24hStyle.addEventListener('change', function(e) {
    rockySimulator.set24hStyle(e.target.checked);
  });
});

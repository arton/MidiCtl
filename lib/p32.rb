#! /usr/bin/env ruby

# play.rb: Written by Tadayoshi Funaba 1999-2001
# $Id: play.rb,v 1.13 2001-05-13 00:00:23+09 tadf Exp $

# modifed by arton on 5 Nov 2001 for Win32 with Win32OLE

require 'smf'
require 'win32ole'
include  SMF

def readsmf(file)
  sq = Sequence.decodefile(file)
  nsq = Sequence.new(0, sq.division)
  ntr = Track.new
  sq.each do |tr|
    tr.pop
    tr.each do |ev|
      ntr << ev
    end
  end
  nsq << ntr
  nsq
end

class Play < Sequence::XSCallback

  def initialize()
    super
    @midi = WIN32OLE.new 'MidiCtl.midiOutInfo'
    @seq = nil
    @ctrlrate = @midi.TimerResolution
  end

  def header(format, ntrks, division, dummy)
    @division = division
  end

  def track_start
    begin
      @seq = @midi.Mapper
    rescue
      fail 'No MIDI ports'
    end
    @tempo = 500000
    @cur = 0
  end

  def track_end
    @seq.close
    @seq = nil
  end

  def delta(delta)
    if delta.nonzero?
      delta2 = delta.to_f * @tempo * @ctrlrate / 1000 / @division
      cur = @cur + delta2
      if cur.to_i > @cur.to_i
	@midi.Wait delta2, 1
      else
	puts "delayed\n"
      end
      @cur = cur
    end
  end

  def noteoff(ch, note, vel)
    @seq.Send((vel << 16) | (note << 8) | ch | 0x80)
  end

  def noteon(ch, note, vel)
    @seq.Send((vel << 16) | (note << 8) | ch | 0x90)
  end

  def polyphonickeypressure(ch, note, val)
    @seq.Send((val << 16) | (note << 8) | ch | 0xa0)
  end

  def controlchange(ch, num, val)
    @seq.Send((val << 16) | (num << 8) | ch | 0xb0)
  end

  def programchange(ch, num)
    @seq.Send ((num << 8) | ch | 0xc0)
  end

  def channelpressure(ch, val)
    @seq.Send ((val << 8) | ch | 0xd0)
  end

  def pitchbendchange(ch, val)
    val += 0x2000
    lsb = val & 0x7f
    msb = (val >> 7) & 0x7f
    @seq.Send ((msb << 16) | (lsb << 8) | ch | 0xe0)
  end

  def channelmodemessage(ch, num, val)
    @seq.Send ((val << 16) | (num << 8) | ch | 0xb0)
  end

  def exclusivefx(data)
    puts "exclusivef(x#{data})\n"
=begin
    data.each_byte do |x|
      @seq.midiout(0, x)
    end
=end
  end

  def exclusivef0(data)
    puts "exclusivef0(x#{data})\n"
=begin
    @seq.midiout(0, 0xf0)
    exclusivefx(data)
=end
  end

  def exclusivef7(data)
    puts "exclusivef7(x#{data})\n"
#    exclusivefx(data)
  end

  def settempo(tempo)
    @tempo = tempo
  end

end

class Play2 < Play
  def track_start
    @seq = nil
    @midi.each do |info|
      puts info.ProductName
      y = $stdin.gets
      if y.strip == 'y'
        @seq = info.Device
        break
      end
    end
    begin
      @seq = @midi.Mapper unless @seq
    rescue
      fail 'No MIDI ports'
    end
    @tempo = 500000
    @cur = 0
  end
end

$*.each do |file| Sequence::WS.new(readsmf(file), Play2.new).read end

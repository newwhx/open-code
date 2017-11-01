#!/usr/bin/env ruby

class SongList
	MAX_TIME = 5 * 60 # 5 minutes

	def SongList.is_too_long(song)
		(song.duration > MAX_TIME)
	end
end

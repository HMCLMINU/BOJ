from functools import cmp_to_key

def album_compare(album1, album2):
    if album1.play < album2.play:
        return 1
    elif album1.play == album2.play:
        if album1.track < album2.track:
            return -1
        else:
            return 1
    else:
        return -1
    
def solution(genres, plays):
    answer = []
    dic = {}
    album_list = []
    for idx, genre in enumerate(genres):
        dic[genre] = dic.get(genre, 0) + plays[idx]
        album_list.append(album(genre, plays[idx], idx))

    dic = sorted(dic.items(), key=lambda dic:dic[1], reverse=True)
    album_list = sorted(album_list, key=cmp_to_key(album_compare))
    # print(dic)

    while len(dic) > 0:
        # 정렬했으므로 dic은 list 타입이다
        play_genre = dic.pop(0)
        # print(play_genre)
        cnt = 0;
        for ab in album_list:
            if play_genre[0] == ab.genre:
                answer.append(ab.track)
                cnt += 1
            if cnt == 2:
                break

    return answer

class album:
    def __init__(self, genre, play, track):
        self.genre = genre
        self.play = play
        self.track = track
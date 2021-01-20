/*
    기지국 설치
    https://programmers.co.kr/learn/courses/30/lessons/12979
    
    [1, stations[0] - w), [stations[0] + w, stations[1] + w), ..., [stations[stations.length - 1] + w, n)에 기지국이 필요하다.
    각 구간별 필요 기지국 수는 ceil(구간의 길이 / (2w + 1))
*/

function solution(n, stations, w) {
    let result = 0
    let need_begin = 1
    stations.push(n + w + 1)
    for(let i in stations){
        result += Math.ceil((stations[i] - w - need_begin)/(w*2+1))
        need_begin = stations[i] + w + 1
    }
    return result
}
/*
    2주차
                  이번주 위클리 문제
    https://programmers.co.kr/learn/courses/30/lessons/83201
*/
function solution(scores)
{
    return scores
        .map((score,i)=>{
            return scores.map(v=>v[i])
        })
        .map((score,i)=>{
            let sum = score.reduce((a,b)=>a+b)
            let avg = sum / score.length
            
            let m = score.splice(i, 1)[0]
        
            if(m > Math.max.apply(null,score) || m < Math.min.apply(null,score)){
                sum -= m
                avg = sum / score.length
            }

            return 'FFFFFDDCBAA'[Math.floor(avg/10)]
        })
        .join('')
}
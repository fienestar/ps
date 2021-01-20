/*
    https://programmers.co.kr/learn/courses/30/lessons/42587
    프린터

    문제 설명 그대로 짜면 된다.
*/

function solution(priorities, location) {
    priorities = priorities.map((el,i)=>({value: el}))
    priorities[location].me = true
    let index = 0
    while(priorities.length){
        let front = priorities.shift()
        if(priorities.some(el=>el.value > front.value)){
            priorities.push(front)
            continue
        }
        
        ++index
        
        if(front.me)
            return index
    }
    return answer;
}
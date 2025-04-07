function generateDeck() {
    const suits = ['♠', '♥', '♦', '♣'];
    const ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'];
    const deck = [];
  
    for (let suit of suits) {
        for (let rank of ranks) {
            deck.push({ rank, suit });
        }
    }
  
    return deck;
}
  
function shuffleDeck(deck) {
    for (let i = deck.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [deck[i], deck[j]] = [deck[j], deck[i]];
    }
}
  
function dealCards(deck, numCards) {
    return deck.slice(0, numCards);
}
  
function checkHand(hand) {
    // 예를 들어 손패의 카드 5장이 다음과 같다고 가정
    /*
    hand = [
        { rank: 'A', suit: '♠' },
        { rank: '3', suit: '♥' },
        { rank: 'A', suit: '♦' },
        { rank: '7', suit: '♣' },
        { rank: 'J', suit: '♠' }
    ];
    */

    // hand에 있는 각 카드 객체에서 rank (숫자나 문자)를 추출해 배열로 만듦
    // ranks = ['A', '3', 'A', '7', 'J']
    const ranks = hand.map(card => card.rank);

    // hand에 suit(문양)을 추출해 배열로 만듦(구현)
    const suits = hand.map(card => card.suit);

    // reduce 함수를 사용하여 각 랭크가 몇 번 등장하는지 세어 counts 객체에 저장
    // counts = {A: 2, J: 1, 7: 1, 3: 1}
    const counts = ranks.reduce((acc, rank) => {
        acc[rank] = (acc[rank] || 0) + 1;
        return acc;
    }, {});
  
    // Object.values(counts)로 각 랭크의 등장 횟수를 배열로 만들고, 그 중에서 2회 이상 중복된 값들을 다시 배열 duplicates에 저장
    // Object.values(counts) = [2, 1, 1, 1]
    // duplicates =  [2]
    const duplicates = Object.values(counts).reduce((acc, count) => {
      if (count > 1) acc.push(count);
      return acc;
    }, []);
    
    function getRankValue(rank) {//rank를 문자에서 숫자로 바꾸는 함수(구현)
        const rankValues = {
            '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8,
            '9': 9, '10': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14
        };
        return rankValues[rank];
    }

    function isStraight(ranks) {//스트레이트 유무 여부 확인(구현)
        const rankValues = ranks.map(rank => getRankValue(rank)).sort((a, b) => a - b);
        
        // A-2-3-4-5 케이스 처리 (A를 1로 간주)
        if (rankValues.join(',') === '2,3,4,5,14') {
            return true;
        }
        
        // 일반적인 스트레이트 확인
        for (let i = 1; i < rankValues.length; i++) {
            if (rankValues[i] !== rankValues[i-1] + 1) {
                return false;
            }
        }
        return true;
    }
    const suitCounts = suits.reduce((acc, suit) => {
        acc[suit] = (acc[suit] || 0) + 1;
        return acc;
    }, {});
    // 로열 스트레이트 플러쉬, (같은 suit의 A, K, J, Q, 10), 이러거는 확률자체가 매우 낮기 때문에 일일히 검사보다는 다 돌린 후에 찾는 게 유리
    // (미구현)

    // 스트레이트 플러쉬 (같은 suit의 연속된 rank 5장)
    // (미구현)

    // 포 오브 어 카인드, 포카드 (같은 rank 4장)
    if (duplicates.includes(4)) return "Four of a Kind";

    // 풀하우스 (트리플+페어)
    if (duplicates.includes(3) && duplicates.includes(2)) return "Full House";

    // 플러쉬 (같은 suit 5장)(구현)
    if (Object.values(suitCounts).some(count => count >= 5)) return "Flush";

    // 스트레이트 (연속된 rank 5장(구현)
    if(isStraight(ranks)) return "Straight";

    // 쓰리 오브 어 카인드, 트리플 (같은 rank 3장)
    if (duplicates.includes(3)) return "Three of a Kind";

    // 투페어 (두쌍의 페어)
    if (duplicates.length === 2) return "Two Pair";

    // 원페어 (같은 rank 2장)
    if (duplicates.includes(2)) return "One Pair";

    return "No Combination";
}

function main() {
    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
      });

    rl.question('포커 게임을 몇 번할 것인지 입력하세요', input => {
        const num = parseInt(input);
        const hands = [];
        const combinations = [];
        for(let i=0;i<num;i++){
            const deck = generateDeck();
            shuffleDeck(deck);
            hands[i] = dealCards(deck, 7);//게임마다 hand를 담은 배열
        }
    
        for(let i=0;i<num;i++){
        // console.log("Your hand:", hands[i].map(card => `${card.suit}${card.rank}`).join(', '));
        // console.log("Combination:", checkHand(hands[i]));
        combinations.push(checkHand(hands[i]));
        }
        const combination_counts = combinations.reduce((acc, count) => {
            acc[count] = (acc[count] || 0) + 1;
            return acc;
        }, {});
        
        // 빈도 기준 내림차순으로 정렬렬
        const sortedResults = Object.entries(combination_counts)
        .sort((a, b) => b[1] - a[1]); 

        console.log(num,"번 포커게임의 결과는 ",sortedResults);//이부분 배열을 확률순이나 가나다순으로 배열하는게 좋음
        
        rl.close();
    });     

}
  
main();


/* 참고 - map 함수
배열 원소들에 대해 map 함수 내의 내용을 실행하여 새로운 배열을 만듦
const numbers = [1, 2, 3, 4];
const even = numbers.map( num => num*2 ); // [2, 4, 6, 8]
*/

/* 참고 - reduce 함수
배열 원소 값들을 누적(accumulate)하여 압축. acc에 누적값이 쌓임
const numbers = [1, 2, 3, 4];
const sum = numbers.reduce( (acc, num) => acc + num); // 10
*/
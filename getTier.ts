
type EmojiRequest = '1️⃣' | '2️⃣' | '3️⃣' | '4️⃣' | '5️⃣'

export interface Tier {
    name: string;
    icon: {
        type: 'external',
        external: {
            url: string;
        }
    } | {
        type: 'emoji',
        emoji: EmojiRequest;
    }
}

export function getTier(tier: string): Tier {

    switch (tier) {

        case 'Lv1':
            return { name: 'Lv1', icon: { type: 'emoji', emoji: "1️⃣" } };
        case 'Lv2':
            return { name: 'Lv2', icon: { type: 'emoji', emoji: '2️⃣' } };
        case 'Lv3':
            return { name: 'Lv3', icon: { type: 'emoji', emoji: '3️⃣' }};
        case 'Lv4':
            return { name: 'Lv4', icon: { type: 'emoji', emoji: '4️⃣' } };
        case 'Lv5':
            return { name: 'Lv5', icon: { type: 'emoji', emoji: '5️⃣' } };

        case '브론즈5':
        case 'Bronze5':
        case 'bronze5':
        case 'Bronze V':
        case 'bronze V':
            return { name: '브론즈5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/1.svg" } } };

        case '브론즈4':
        case 'Bronze4':
        case 'bronze4':
        case 'Bronze IV':
        case 'bronze IV':
            return { name: '브론즈4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/2.svg" } } };

        case '브론즈3':
        case 'Bronze3':
        case 'bronze3':
        case 'Bronze III':
        case 'bronze III':
            return { name: '브론즈3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" } } };

        case '브론즈2':
        case 'Bronze2':
        case 'bronze2':
        case 'Bronze II':
        case 'bronze II':
            return { name: '브론즈2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" } } };

        case '브론즈1':
        case 'Bronze1':
        case 'bronze1':
        case 'Bronze I':
        case 'bronze I':
            return { name: '브론즈1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" } } };

        case '실버5':
        case 'Silver5':
        case 'silver5':
        case 'Silver V':
        case 'silver V':
            return { name: '실버5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/6.svg" } } };

        case '실버4':
        case 'Silver4':
        case 'silver4':
        case 'Silver IV':
        case 'silver IV':
            return { name: '실버4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/7.svg" } } };

        case '실버3':
        case 'Silver3':
        case 'silver3':
        case 'Silver III':
        case 'silver III':
            return { name: '실버3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" } } };

        case '실버2':
        case 'Silver2':
        case 'silver2':
        case 'Silver II':
        case 'silver II':
            return { name: '실버2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" } } };

        case '실버1':
        case 'Silver1':
        case 'silver1':
        case 'Silver I':
        case 'silver I':
            return { name: '실버1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/10.svg" } } };

        case '골드5':
        case 'Gold5':
        case 'gold5':
        case 'Gold V':
        case 'gold V':
            return { name: '골드5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/11.svg" } } };

        case '골드4':
        case 'Gold4':
        case 'gold4':
        case 'Gold IV':
        case 'gold IV':
            return { name: '골드4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/12.svg" } } };

        case '골드3':
        case 'Gold3':
        case 'gold3':
        case 'Gold III':
        case 'gold III':
            return { name: '골드3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/13.svg" } } };

        case '골드2':
        case 'Gold2':
        case 'gold2':
        case 'Gold II':
        case 'gold II':
            return { name: '골드2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/14.svg" } } };

        case '골드1':
        case 'Gold1':
        case 'gold1':
        case 'Gold I':
        case 'gold I':
            return { name: '골드1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/15.svg" } } };

        case '플래티넘5':
        case 'Platinum5':
        case 'platinum5':
        case 'Platinum V':
        case 'platinum V':
            return { name: '플래티넘5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/16.svg" } } };

        case '플래티넘4':
        case 'Platinum4':
        case 'platinum4':
        case 'Platinum IV':
        case 'platinum IV':
            return { name: '플래티넘4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/17.svg" } } };

        case '플래티넘3':
        case 'Platinum3':
        case 'platinum3':
        case 'Platinum III':
        case 'platinum III':
            return { name: '플래티넘3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/18.svg" } } };

        case '플래티넘2':
        case 'Platinum2':
        case 'platinum2':
        case 'Platinum II':
        case 'platinum II':
            return { name: '플래티넘2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/19.svg" } } };

        case '플래티넘1':
        case 'Platinum1':
        case 'platinum1':
        case 'Platinum I':
        case 'platinum I':
            return { name: '플래티넘1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/20.svg" } } };

        case '다이아5':
        case 'Diamond5':
        case 'diamond5':
        case 'Diamond V':
        case 'diamond V':
            return { name: '다이아5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/21.svg" } } };

        case '다이아4':
        case 'Diamond4':
        case 'diamond4':
        case 'Diamond IV':
        case 'diamond IV':
            return { name: '다이아4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/22.svg" } } };

        case '다이아3':
        case 'Diamond3':
        case 'diamond3':
        case 'Diamond III':
        case 'diamond III':
            return { name: '다이아3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/23.svg" } } };

        case '다이아2':
        case 'Diamond2':
        case 'diamond2':
        case 'Diamond II':
        case 'diamond II':
            return { name: '다이아2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/24.svg" } } };

        case '다이아1':
        case 'Diamond1':
        case 'diamond1':
        case 'Diamond I':
        case 'diamond I':
            return { name: '다이아1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/25.svg" } } };

        case '루비5':
        case 'Ruby5':
        case 'ruby5':
        case 'Ruby V':
        case 'ruby V':
            return { name: '루비5', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/26.svg" } } };

        case '루비4':
        case 'Ruby4':
        case 'ruby4':
        case 'Ruby IV':
        case 'ruby IV':
            return { name: '루비4', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/27.svg" } } };

        case '루비3':
        case 'Ruby3':
        case 'ruby3':
        case 'Ruby III':
        case 'ruby III':
            return { name: '루비3', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/28.svg" } } };

        case '루비2':
        case 'Ruby2':
        case 'ruby2':
        case 'Ruby II':
        case 'ruby II':
            return { name: '루비2', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/29.svg" } } };

        case '루비1':
        case 'Ruby1':
        case 'ruby1':
        case 'Ruby I':
        case 'ruby I':
            return { name: '루비1', icon: { type: 'external', external: { url: "https://d2gd6pc034wcta.cloudfront.net/tier/30.svg" } } };

        default:
            return { name: '오류', icon: { type: 'external', external: { url: 'https://upload.wikimedia.org/wikipedia/commons/5/5f/Red_X.svg' } } };
    }
}

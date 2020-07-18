// Search in: "static void regen_spawn(LPREGEN regen, bool bOnce)"
 
        if (ch && !bOnce)
            ch->SetRegen(regen);
           
// Replace with:
 
        if (ch && !bOnce)
#ifdef ENABLE_NOTICE_REGEN
        {
            if (ch->IsMonster() && ch->GetMobRank() >= MOB_RANK_BOSS)
            {
                char buf[256];
                snprintf(buf, sizeof(buf), "[***<< BalanzaDev - Notice Boss >>***]---> %s e' di nuovo fra noi e sta facendo scappare i nostri soldati, correte in soccorso!", ch->GetName());
                SendNotice(buf);
            }
            ch->SetRegen(regen);
        }
#else
            ch->SetRegen(regen);
#endif
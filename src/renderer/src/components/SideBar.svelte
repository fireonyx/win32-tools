<script lang="ts">
	import Icon from "@iconify/svelte";

    interface TypeEl {
        icon: string;
        url: string;
	}

	const elements: TypeEl[] = [
        {
            icon: 'fluent:tv-16-regular',
			url: '/'
		},
		{
			icon: 'fluent:hard-drive-20-regular',
			url: '/memory'
		},
		{
			icon: 'fluent:connector-16-regular',
			url: '/linking'
		}
    ];
</script>

<section class="side-bar">
	<div class="top">
		{#each elements as element}
			<a href="{element.url}">
				<Icon icon="{element.icon}" />
			</a>
		{/each}
	</div>

	<div class="bottom">
		<a href="/settings">
			<Icon icon="fluent:settings-16-regular" />
		</a>
	</div>
</section>

<style lang="scss">
@import "../Config.scss";

.side-bar {
  display: flex;
  flex-direction: column;
  justify-content: space-between;
  align-items: center;
  width: 60px;
  height: calc(100vh - 50px);
  padding: 0 0 10px 0;
  background: $l2;

  .top {
	display: flex;
	flex-direction: column;
	align-items: center;
	width: 100%;
	height: 100%;
	gaP: 5px;
  }

  a {
	display: flex;
	width: 40px;
	height: 40px;
	border-radius: 4px;
	align-items: center;
	justify-content: center;
	color: $f2;
	transition: $ti1;

	&:hover {
	  transition: $to1;
	  background: $d4;
    }
  }

  .bottom {
	display: flex;
	flex-direction: column;
	align-items: center;
	width: 100%;
	gap: 5px;
  }
}
</style>